Psion-bcc: A Software Development Kit for Psion palmtop computers
=================================================================

Version 0.05
not yet Released on 5th September 1997

Introduction
------------
This is a C development environment for the Psion Series 3/3a/3c
(EPOC 16) palmtop computers. It has been developed from the SDK
used by the Linux-8086 project. (Credits are given in the
CREDITS.TXT file.)

It is distributed under the GNU Public License, a copy of which
may be found in the COPYING.TXT file. Although I release all
source code to this package, I do ask one thing of anyone who
modifies it:
If it's a bug fix or enhancement to this package, please let me
know (and also the Linux-8086 people) as it will be of benefit to
all users. I have seen packages fragment into several different
versions as a result of neglecting this - the result is not good.
So please try to keep one master source tree!

The SDK is hosted on Linux 2.0, and MS-DOS. It should work under 
previous versions of Linux. It should also be portable to other 
systems, but I haven't the resources to do this. The MSDOS porting
work was done by Stephen Henson, Nic Wise. 

As of release 0.05, the SDK contains the header files from
Psion's own C software development kit. Psion have very kindly
allowed me to redistribute their headers.. here is the email I
received from them to this effect:

=================================================================
Date: Thu, 04 Sep 97 13:35:40 GMT
From: "Ali Manson" <Ali-Manson@psion.com>
To: "Matt J. Gumbley" <matt@gumbley.demon.co.uk>
Subject: Re: Redistributing C SDK headers...
     
 Hello Matt
     
 Apologies for the delay. We have no problem with your
 distributing the header files.
     
 However, the header files must be distributed *intact*.
 As such, this means that the #pragmas will remain. I wouldn't
 have thought that it would be too much trouble to have your
 compiler parse out the #pragmas.
     
 If you can accept this simple restriction, you have our
 permission.
     
 with best regards
     
 Ali
=================================================================

As per the message, the contents of the include directory of this
package hold the entire contents of my V2.20 SIBO C SDK's include
directory - that is, the core (required) includes, and all
includes from the optional packages. None of these files have
been altered in any way. There are no files from the Topspeed
compiler's include directory.

The compiler has been altered to filter out the #pragmas - it
does not use them, as yet....


Availability
------------
The latest release of this package may be found at my home page:
http://www.gumbley.demon.co.uk/psion-c.html
And also from the main project FTP archive:
ftp://argon.dcs.kcl.ac.uk/

You will find three packages there: a source release, and two binaries
release, one for Linux and one for MSDOS. All releases include this 
information. Their names are:

Linux Binaries: psion-bcc-bin-x.xx.tar.gz or bcclxxx.zip
MSDOS Binaries: psion-bcc-dos-x.xx.tar.gz or bccdxxx.zip
Source:         psion-bcc-src-x.xx.tar.gz or bccsxxx.zip

(Where x.xx is the version number given at the top of this document.)

In the near future, I'll be distributing a small bootable Linux disk
set containing all you need to develop programs for the Psion using the
bcc toolset, for those who haven't ditched DOS and installed a Real OS :)

Keep your browser pointed to my home page for details.


LINUX-SPECIFIC RELEASE NOTES
============================

Installing the Linux binary release
-----------------------------------
1) Log in as root.
2) Copy the release archive file to your root directory.
3) Change to the root directory.
4) Unarchive:
     tar zxvf psion-bcc-bin-x.xx.tar.gz
   Once this is done new files will be below /usr/bcc/*
5) Add /usr/bcc/bin to your PATH environment variable, and /usr/bcc/man
   to your MANPATH environment variable. The details of this are
   shell-specific, but if you are using bash, place the following
   commands in your .profile or .bashrc file:
     export PATH=$PATH:/usr/bcc/bin
     export MANPATH=$MANPATH:/usr/bcc/man


Installing the source release on Linux machines
-----------------------------------------------
1) Log in as yourself, you don't have to be root.
2) Copy the release archive file to any directory you like.
3) Unarchive:
     tar zxvf psion-bcc-src-x.xx.tar.gz
4) This will create a directory psion-bcc in the current directory
   containing the source tree.


Building the source release on Linux machines
---------------------------------------------
From the psion-bcc directory:
$ cp makelin.def make.def
$ make toolset
$ make library
$ su -c "make install"

Once this is done new files will be below /usr/bcc/*
NB: you may experience hell when building this. If you work out why libc
    is such a complete $%*!@#$~ to build, please let me know :)



MS-DOS-SPECIFIC RELEASE NOTES
=============================

Installing the MS-DOS binary release
------------------------------------
You will need a DPMI server, or a DOS system which supports DPMI, such as
Windows 95. bcc should also work on OS/2 (see the DJGPP FAQ)

Use the following command to unarchive the package:

  C:\FRED> cd \
  C:\> pkunzip -d bccbxxx.zip            (xxx is the current version)

The binary release should be expanded from the root directory. The directory
C:\BCC\ will be created. Other drives are fine, just add the executables
directory to your PATH by adding the following line to your AUTOEXEC.BAT file:

  set PATH=%PATH%;C:\BCC\BIN


Installing the source release on MS-DOS machines
------------------------------------------------
The source does not have to be any particular directory, C:\BCCSRC is fine, 
although since I use Windows 95, I put it in C:\My Documents\bcc

All filenames are in 8.3 format.

Use these commands to install:

  C:\FRED> cd \
  C:\> mkdir bccsrc
  C:\> cd bccsrc
  C:\BCCSRC> pkunzip -d \bccsxxx.zip     (xxx is the current version)

(This assumes that the bccsxxx.zip file is located in the root directory)


Building the source release on MS-DOS machines
----------------------------------------------
You will need DJGPP, the DOS port of gcc installed. For more details, see
http://www.delorie.com/

Set up the package to use DOS settings:

  C:\BCCSRC> copy makedos.def make.def

<Steve, could you add these bits please? Thanks! -- MJG>



Using the psion-bcc toolset
---------------------------
There are manual pages in the /usr/bcc/man subdirectory which may be consulted
for the operation of the programs. Please note that certain programs in this
toolset have the same name as existing Linux development tools - notably as86
and ld86 - you will get conflicts between the two sets of manual pages.  
The bcc compiler front end does not get confused when running the assembler 
and linker, and always uses the one in /usr/bcc/lib/bcc.  It defaults to using 
/usr/bcc/include and /usr/bcc/lib: the libraries and include files are copied
to these locations by install.

The as86 and ld86 with this SDK are different from the ones needed for the
Linux-i386 kernel, but can replace them: the standard 'binutils' versions
ones _will not_ work correctly here!

There are some trivial sample programs in the 'examples' directory of the
source release. Given a single source file 'fred.c', a .img file can be
built using:

    bcc fred.c -o fred.img


Note about Linux-8086
---------------------
This package can still be used to develop and run programs for Linux-8086.
(I've merely added options, not removed any. I haven't tested whether you
can still build Linux-8086, but I can't see why not).

However, the runtime support, 'elksemu', is not part of this package. The
original documentation had this to say:

"Unfortunatly, the DOSEMU folks have been using the '-r' option of ld86
This version does accept '-r' but it generates _LINUX_ a.out object files.
I think they should really be using 'as86_encap'. Neverthless this ld86
will call a program called /usr/bin/ld86r if it's given -r without -N.

I _strongly_ suggest you install the kernel patch or load the module in
the elksemu directory in your Linux-i386 kernel, it makes things _much_
easier.

-Rob."


Future plans
------------
Fix the BUGS

The bcc-cc1 program may get replaced by the CPOC front end - investigating.

Produce pure small model executables, instead of tiny model.

Add some optimisation.

Add pragma support for registerised function parameters.


Author / Packager
-----------------
As I didn't write much of this, I can't claim authorship. I wrote some of the 
programs in the tools directory based on publically available material, fixed 
some bugs and made some slight enhancements to the toolset in general. Others 
have helped with the package: see the CREDITS.TXT file.

I can be contacted via email at: matt@gumbley.demon.co.uk

--
Matt J. Gumbley

