include ../make.def

all: crt0.o

crt0.o : crt0.s
	as86 -0 crt0.s -o crt0.o

install: crt0.o
	install -d $(LIBDIR)/i86
	install -m 755 crt0.o $(LIBDIR)/i86/crt0.o

clean:
	rm -f *.o


