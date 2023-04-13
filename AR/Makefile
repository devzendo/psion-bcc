include ../make.def

OBJS =	ar86$(OBJ)

PROG = ar86$(EXE)

all: ar86$(EXE)

ar86$(EXE): $(OBJS)
	$(CC) $(LDCREAT)$(PROG) $(LDFLAGS) $(OBJS)

install: ar86$(EXE)
	install -d $(BINDIR)
	install -m 755 ar86$(EXE) $(BINDIR)
	install -d $(MANDIR)
	install -m 644 ar86.1 $(MANDIR)/ar86.1

clean:
	rm -f *$(OBJ) ar86$(EXE)

ar86$(OBJ): ar86.c 

ar86.img: ar86.pr 
	tsc /m ar86.pr /smain=ar86

