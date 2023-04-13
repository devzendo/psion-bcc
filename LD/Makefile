
include ../make.def
CFLAGS  =$(CCFLAGS) -DREL_OUTPUT

# May need some of these if the auto-sense fails.
# -DV7_A_OUT -DBSD_A_OUT -DSTANDARD_GNU_A_OUT

OBJS= dumps.o io.o ld.o readobj.o table.o typeconv.o linksyms.o \
      writex86.o writebin.o

all: ld86

ld86: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

install: ld86 ld86.1
	install -d $(LIBDIR)
	install -m 755 ld86 $(LIBDIR)/ld86
	install -d $(MANDIR)
	install -m 644 ld86.1 $(MANDIR)/ld86.1

clean:
	rm -f $(OBJS) ld86

$(OBJS): align.h ar.h bindef.h byteord.h config.h const.h globvar.h obj.h \
	 syshead.h type.h x86_aout.h
