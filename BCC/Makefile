include ../make.def

WFLAGS=-Wall
WALL  =-Wall -Wtraditional -Wshadow -Wid-clash-14 -Wpointer-arith \
       -Wcast-qual -Wcast-align -Wconversion -Waggregate-return \
       -Wstrict-prototypes -Wmissing-prototypes -Wredundant-decls \
       -Wnested-externs -Winline 

# Add -DDOS in here if you want the fork()/execv() pair replaced by system()

CFLAGS	= $(WFLAGS) -fno-strength-reduce -O2 \
	-DLOCALPREFIX="\"$(INSTDIR)\"" -DANSI_SUPPORT \
	-DDEFARCH=0 

LDFLAGS	= -N -s -static
OBJS	= bcc-cc1$(OBJ) codefrag$(OBJ) debug$(OBJ) declare$(OBJ) \
	express$(OBJ) exptree$(OBJ) floatop$(OBJ) function$(OBJ) \
	gencode$(OBJ) genloads$(OBJ) glogcode$(OBJ) hardop$(OBJ) \
	input$(OBJ) label$(OBJ) loadexp$(OBJ) longop$(OBJ) output$(OBJ) \
	preproc$(OBJ) preserve$(OBJ) scan$(OBJ) softop$(OBJ) \
	state$(OBJ) table$(OBJ) type$(OBJ) assign$(OBJ)	


all:	bcc$(EXE) bcc-cc1$(EXE)

bcc$(EXE): bcc$(OBJ)
	$(CC) $(CFLAGS) bcc$(OBJ)  $(LDFLAGS) -o $@

ccc$(EXE): bcc$(OBJ)
	$(CC) -DCCC $(CFLAGS bcc$(OBJ) ) $(LDFLAGS) -o $@

bcc-cc1$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -f bcc$(EXE) bcc-cc1$(EXE) ccc$(EXE) bcc$(OBJ) $(OBJS)

install: bcc$(EXE) bcc-cc1$(EXE) bcc.1
	install -d $(BINDIR)
	install -m 755 bcc$(EXE) $(BINDIR)
	install -d $(LIBDIR)
	install -m 755 bcc-cc1$(EXE) $(LIBDIR)
	install -d $(MANDIR)
	install -m 644 bcc.1 $(MANDIR)
