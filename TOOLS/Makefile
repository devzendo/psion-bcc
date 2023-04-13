CFLAGS += -g 
CFLAGS -= -Wstrict-prototypes

include ../make.def

CFLAGS += -w

PROGS = imgconv imgdump makelist disimg

all: $(PROGS)

imgconv.o : imgconv.c img.h

imgdump.o : imgdump.c img.h

imgconv: imgconv.o
	$(CC) $(LDFLAGS) imgconv.o -o $@

imgdump : imgdump.o
	$(CC) $(LDFLAGS) imgdump.o -o $@

makelist.o : makelist.c

getopt.o : getopt.c

makelist: makelist.o getopt.o
	$(CC) $(LDFLAGS) makelist.o getopt.o -o $@

install: $(PROGS)
	install -d $(LIBDIR)
	install -m 755 imgconv $(LIBDIR)/imgconv
	install -d $(BINDIR)
	install -m 755 imgdump $(BINDIR)/imgdump
	install -m 755 makelist $(BINDIR)/makelist
	install -m 755 mkdepends $(BINDIR)/mkdepends
	install -m 755 disimg $(BINDIR)
	install -d $(MANDIR)
	install -m 644 imgconv.1 $(MANDIR)
	install -m 644 disimg.1 $(MANDIR)

clean:
	rm -f *.o $(PROGS)

DISOBJ = disrel.o dismain.o distabs.o dishand.o disfp.o

disimg:	$(DISOBJ)
	$(CC) $(LDFLAGS) -o disimg $(DISOBJ) -o $@

$(DISOBJ): dis.h 


