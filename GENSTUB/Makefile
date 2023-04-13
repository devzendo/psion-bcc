include ../make.def
include ../libc/make.def


libepoc.a: genlib.tbl genstub.awk
	awk -f genstub.awk < genlib.tbl
	bcc -c epoc*.s
	ar86 cv libepoc.a epoc*.o

clean:	
	rm -f *.o *.s libepoc.a

install: libepoc.a
	install -d $(LIBDIR)/$(LIB_CPU)
	install -m 644 libepoc.a $(LIBDIR)/$(LIB_CPU)

