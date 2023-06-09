# Makefile for dis

# @(#) Makefile, Ver. 2.1 created 00:00:00 87/09/01
# Makefile for 8088 symbolic disassembler

# Copyright (C) 1987 G. M. Harding, all rights reserved.
# Permission to copy and redistribute is hereby granted,
# provided full source code, with all copyright notices,
# accompanies any redistribution.

# This Makefile  automates the process of compiling and linking
# a symbolic  object-file  disassembler  program  for the Intel
# 8088 CPU. Relatively machine-independent code is contained in
# the file dismain.c; lookup tables and handler routines, which
# are by their nature  machine-specific,  are  contained in two
# files named distabs.c and dishand.c,  respectively.  (A third
# machine-specific file, disfp.c, contains handler routines for
# floating-point  coprocessor opcodes.)  A header file,  dis.h,
# attempts to mediate between the machine-specific and machine-
# independent portions of the code. An attempt has been made to
# isolate machine  dependencies and to deal with them in fairly
# straightforward ways. Thus, it should be possible to target a
# different CPU by rewriting the handler  routines and changing
# the initialization  data in the lookup tables.  It should not
# be necessary to alter the formats of the tables.

include ../make.def

CFLAGS += -w 

OBJ = disrel.o dismain.o distabs.o dishand.o disfp.o

all:	dis88

dis88:	$(OBJ)
	$(CC) $(LDFLAGS) -o dis88 $(OBJ)

install:	dis88 dis88.1
	install -d $(BINDIR)
	install -m 755 dis88   $(BINDIR)
	install -d $(MANDIR)
	install -m 644 dis88.1 $(MANDIR)

$(OBJ): dis.h a.out.h

a.out.h:
	ln -s ../libc/include/a.out.h .

clean:	
	rm -f *.bak *.lst *.o core dis88 a.out.h

