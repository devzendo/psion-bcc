include ../make.def

OBJS =	as$(OBJ) assemble$(OBJ) error$(OBJ) express$(OBJ) \
	genbin$(OBJ) genlist$(OBJ) genobj$(OBJ) gensym$(OBJ) \
	keywords$(OBJ) macro$(OBJ) mops$(OBJ) pops$(OBJ) readsrc$(OBJ) \
	scan$(OBJ) table$(OBJ) typeconv$(OBJ)

PROG = as86$(EXE)

all: as86$(EXE)


as$(OBJ): as.c const.h type.h byteord.h macro.h file.h flag.h globvar.h
assemble$(OBJ): assemble.c const.h type.h address.h globvar.h opcode.h scan.h
error$(OBJ): error.c const.h type.h
express$(OBJ): express.c const.h type.h address.h globvar.h scan.h source.h
genbin$(OBJ): genbin.c const.h type.h address.h file.h globvar.h
genlist$(OBJ): genlist.c const.h type.h address.h flag.h file.h globvar.h \
	macro.h scan.h  source.h
genobj$(OBJ): genobj.c const.h type.h address.h file.h globvar.h
gensym$(OBJ): gensym.c const.h type.h flag.h file.h globvar.h
keywords$(OBJ): keywords.c const.h type.h globvar.h opcode.h
macro$(OBJ): macro.c const.h type.h globvar.h scan.h macro.h
mops$(OBJ): mops.c const.h type.h globvar.h opcode.h scan.h address.h
pops$(OBJ): pops.c const.h type.h address.h flag.h globvar.h opcode.h scan.h
readsrc$(OBJ): readsrc.c const.h type.h flag.h file.h globvar.h macro.h scan.h source.h
scan$(OBJ): scan.c const.h type.h globvar.h scan.h 
table$(OBJ): table.c const.h type.h globvar.h opcode.h scan.h
typeconv$(OBJ): typeconv.c const.h type.h globvar.h

as86$(EXE): $(OBJS)
	$(CC) $(LDCREAT)$(PROG) $(LDFLAGS) $(OBJS) 

install: as86$(EXE)
	install -d $(LIBDIR)
	install -m 755 as86$(EXE) $(LIBDIR)
	sed "s:%%LIBDIR%%:$(LIBDIR):" < asencap > tmp
	install -d $(BINDIR)
	install -m 755 tmp $(BINDIR)/asencap
	-@rm -f tmp
	install -d $(MANDIR)
	install -m 644 as86.1 $(MANDIR)

clean:
	rm -f *$(OBJ) as86$(EXE)
