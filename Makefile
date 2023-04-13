include make.def

PARTS=    ld as ar unproto bcc c86 dis88 tools startup genstub
#LIBS2=    libbsd
LIBS2=    
LIBS=     libc $(LIBS2) 
EXTRAS=   
DISTFILES=Makefile Make.defs README Changes Libc_version Uninstall
DISTDIRS= $(LIBS2) $(EXTRAS)

default: dummy
	@echo "You have to do 'make install' as root"
	@echo Or:
	@echo
	@echo '$ make bcc'
	@echo '$ su -c "make install-bcc"'
	@echo '$ make library'
	@echo '$ su -c "make install-lib"'
	@echo
	@echo "Or do 'make install-all' for _everything_"

dummy:
	@if [ -f .runme ] ; then sh .runme ; rm .runme ; fi

install: install-bcc install-lib 

# Do _everything_!
install-all:
	make realclean
	make config
	make install-bcc
	make install-lib
	make -C dis88 install
	make realclean

config:
	make -C libc config

all: bcc library extras

bcc: dummy
	@for i in $(PARTS) ; do make -C $$i || exit 1; done

realclean:
	@for i in $(PARTS) libc $(DISTDIRS) ; do \
	   if grep -q '^realclean' $$i/Makefile ; then \
	   make -C $$i realclean ; else \
	   make -C $$i clean ; fi ; done

clean:
	@for i in $(PARTS) libc $(DISTDIRS) ; do \
	   make -C $$i clean || exit 1; done

tests: dummy
	@test -f $(BINDIR)/bcc || \
	( echo 'Must do "make install-bcc" first' && exit 1 )
	@test -f $(LIBDIR)/i86/crt0.o || \
	( echo 'Must do "make install-lib" first' && exit 1 )
	@for i in $(TESTDIRS) ; do make -C $$i || exit 1; done

library: dummy
	@test -f $(BINDIR)/bcc || \
	( echo 'Must do "make install-bcc" first' && exit 1 )
	make -C libc 

#	make -C libc PLATFORM=i86-ELKS

extras: dummy
	@for i in $(EXTRAS) ; do make -C $$i || exit 1; done
	
install-bcc: dummy
	@for i in $(PARTS) ; do make -C $$i install || exit 1; done

install-lib: dummy
	@test -f $(BINDIR)/bcc || \
	( echo 'Must do "make install-bcc" first' && exit 1 )
	@for i in $(LIBS) ; do \
	 make -C $$i install || exit 1 ; \
	 done

#	 make -C $$i PLATFORM=i86-ELKS install || exit 1 ; \

install-extras: dummy
	@for i in $(EXTRAS) ; do make -C $$i install || exit 1; done
	
distribution:
	make clean
	sh Build_dist

