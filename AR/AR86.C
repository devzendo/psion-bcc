/*
**	Archiver
**
**	ar [cdrtvx] library file...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include.bcc/ar.h"

#if !defined(WIN32) && !defined(__TSC__)
#include <unistd.h>
#else
#include <io.h>
#endif /* WIN32 */

#ifndef O_BINARY
#define O_BINARY 0
#endif

#define STDOUT	1	/* channel for stdout				*/
#define STDERR	2	/* channel for stderr				*/
#define BSIZE	512	/* size of the input/outut buffer		*/

int	cflag;		/* create - add a new file to the archive	*/
int	dflag;		/* delete - de*ete a file from the archive	*/
int	rflag;		/* replace - replace an exisiting file		*/
int	tflag;		/* table - print a list of files in the archive */
int	vflag;		/* verbose - print additional info		*/
int	xflag;		/* extract - extract a file from the archive	*/

/*
**	Returns the filename component of the name supplied.
*/
static char *
basename(char *name)
{
	return name;
}

/*
**	Search the list of names for the specified name.  If it cannot
**	be found NULL is returned, otherwise a pointer to the found
**	entry is returned.
*/
static char *
find_name(char *name, char**names)
{
	while(*names) {
		if(strcmp(name,*names)==0)
			break;
		names++;
	}
	return *names;
}

/*
**	Deletes the name from the list of names
*/
static void
delete_name(char*name, char**names)
{
	while(*names) {
		if (strcmp(name,*names++)==0) {
			while(*names) {
				*(names-1) = *names;
				names++;
			}
		}
	}
}

/*
**	Write a string to the specified file.
*/
static int
writestr(int fd, char *str)
{
	return write(fd, str, strlen(str));
}

/*
**	Print out a message to stderr and the stop.  The last parameter
**	must be (char*)0.
*/
static void
fatal(char *str, ...)
{
	va_list ap;
	va_start(ap,str);
	do {
		(void)writestr(STDERR,str);
	} while ((str = va_arg(ap, char*))!=0);
	va_end(ap);
	exit(EXIT_FAILURE);
}

/*
**	Write the ASCII value of value to str
*/
static void
ltostr(char *str, long value, int size)
{
	str[--size] = '\0';
	while (value) {
		str[--size] = value % 10 + '0';
		value /= 10;
	}
	while (size) {
		str[--size] = ' ';
	}
}

/*
**	Write out a usage messgae.
*/
static void
usage(void)
{
	fatal("usage: ar c|d|r|t|x archive file...\n",(char*)0);
}

/*
**	Write the buffer to the specified file checking that the
**	write completed with no errors.
*/
static void
arwrite (int fd, void *buf, unsigned len)
{
	if (write(fd, buf, len) != len) {
		fatal("write error\n",(char*)0);
	}
}

/*
**	Open the specified archive for reading.  Checks that the
**	file is actually an archive file.
*/
static int
aropen (char *name)
{
	char hdr[SARMAG];
	int fd;

	fd = open(name,O_RDONLY | O_BINARY);
	if(fd < 0) {
		fatal("unable to open '", name, "'\n", (char*)0);
	}
	if((read(fd,&hdr[0],SARMAG) != SARMAG) ||
	    memcmp(&hdr[0],ARMAG,SARMAG)) {
		fatal("'",name,"' is not an archive file\n",(char *)0);
	}

	return fd;
}

/*
**	Creates a new achive file and writes out the header.
*/
static int
arcreate(char *name)
{
	int fd;
	fd = open(name, O_WRONLY|O_CREAT|O_TRUNC|O_BINARY,0644);
	if (fd < 0) {
		fatal("unable to create '", name, "'\n", (char*)0);
	}
	arwrite (fd, ARMAG, SARMAG);
	return fd;
}

/*
**	Read the archive header for a file
*/
static int
read_file_header(int fd, struct ar_hdr *hptr)
{
	if(read(fd, hptr, sizeof *hptr) != sizeof *hptr) {
		return 0;
	}
	return 1;
}

/******************************************************************************
**
**	Write out a table of contents of the archive.
*/
static void
table_archive (char *arname)
{
	struct ar_hdr	hdr;		/* file archive header */
	int ifd;
        long fsize;
	ifd = aropen(arname);
	while (read_file_header(ifd,&hdr)) {
		(void)writestr(STDOUT,hdr.ar_name);
		if (vflag) {
                writestr (STDOUT,"\t");
                writestr (STDOUT,hdr.ar_size);
		}
		(void)writestr(STDOUT,":\n");
                fsize = strtol (hdr.ar_size, NULL, 10);
                if (fsize & 1) fsize++;
                lseek (ifd, fsize, SEEK_CUR);
	}
}

/******************************************************************************
**
**	Append the specified file to the archive
*/
static void
append_file (int ofd, char *name)
{
	static char buffer[BSIZE];	/* input/output buffer */
	int len;			/* amount read into buffer */
	struct ar_hdr hdr;		/* archive file header */
	struct stat sbuf;		/* buffer for file information */
	int ifd;			/* input file descriptor */

	if (vflag) {
		(void)writestr(STDERR,name);
		(void)writestr(STDERR,":\n");
	}

	/*
	**	Get the file information.
	*/
	if (stat(name,&sbuf) < 0) {
		fatal("unable to stat '",name,"'\n",(char*)0);
	}
	(void)strncpy(&hdr.ar_name[0], basename(name), sizeof hdr.ar_name);
	ltostr(&hdr.ar_size[0], sbuf.st_size, sizeof hdr.ar_size);
	ltostr(&hdr.ar_mode[0], sbuf.st_mode, sizeof hdr.ar_mode);

	/*
	**	Now open the input file.
	*/
	ifd = open (name, O_RDONLY | O_BINARY);
	if (ofd < 0) {
		fatal("unable to open '",name, "'\n",(char*)0);
	}

	/*
	**	The header information for the file must be writen
	**	to the output file.
	*/
	arwrite(ofd, &hdr, sizeof hdr);

	/*
	**	Copy the input file into the archive.
	**	Round up the size written to an even boundary.
	*/
	while((len = read(ifd, buffer, BSIZE)) > 0) {
		arwrite(ofd, buffer, len);
	}
	if (sbuf.st_size % 2)
		arwrite(ofd, buffer, 1);

	/*
	**	Finally close the input file.
	*/
	(void)close(ifd);
}

/*
**	Write the specified files into a newly created archive.
*/
static void
create_archive(char *arname, char **filename)
{
	int fd;
	char *name;

	if (*filename == 0)
		usage();

	fd = arcreate(arname);
	while ((name = *filename++) != 0) {
		append_file(fd, name);
	}
	(void)close(fd);
}

/*
**	Extract the files named in filenames for the archive arname.
**	If filenames is NULL then extract all the file.
*/
static void
extract_archive(char *arname, char**filename)
{
	int fd;
	fatal("x option not yet implemented\n",(char*)0);
	fd = aropen(arname);
}

static void
replace_archive(char *arname, char**filename)
{
	if (*filename == 0) {
		usage();
	}
	fatal("r option not yet implemented\n",(char *)0);
}

static void
delete_archive(char *arname, char**filename)
{
	if (*filename == 0) {
		usage();
	}
	fatal("d option not yet implemented\n",(char*)0);
}

int
main (int argc, char **argv)
{
	char *parg;
	char *arname;
/*#ifdef EPOC
	_openerror(STDERR);
	CommandLineParameters(&argc, &argv);
#endif * EPOC */
	if (argc < 3)
		usage();
	argv++;
	for (parg = *argv++; *parg; parg++) {
		switch(*parg) {
		    case 'c':
			cflag++;
			break;
		    case 'd':
			dflag++;
			break;
		    case 'r':
			rflag++;
			break;
		    case 't':
			tflag++;
			break;
		    case 'v':
			vflag++;
			break;
		    case 'x':
			xflag++;
			break;
		    default:
			usage();
			break;
		}
	}
	if (rflag & !cflag)
		cflag++;
	if ((cflag + dflag + tflag + xflag) > 1)
		usage();
	arname = *argv++;
	if (rflag) {
		replace_archive(arname, argv);
	} else if (cflag) {
		create_archive(arname, argv);
	} else if (tflag) {
		table_archive(arname);
	} else if (xflag) {
		extract_archive(arname, argv);
	} else if (dflag) {
		delete_archive(arname, argv);
	}

	return(EXIT_SUCCESS);
}
