# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=c86 - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to c86 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "c86 - Win32 Release" && "$(CFG)" != "c86 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "c86.mak" CFG="c86 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "c86 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "c86 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "c86 - Win32 Debug"
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "c86 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\c86.exe"

CLEAN : 
	-@erase "$(INTDIR)\Analyze.obj"
	-@erase "$(INTDIR)\Cglbdef.obj"
	-@erase "$(INTDIR)\Cmain.obj"
	-@erase "$(INTDIR)\Decl.obj"
	-@erase "$(INTDIR)\Expr.obj"
	-@erase "$(INTDIR)\Extern.obj"
	-@erase "$(INTDIR)\Gen386.obj"
	-@erase "$(INTDIR)\Gen68k.obj"
	-@erase "$(INTDIR)\Gen86.obj"
	-@erase "$(INTDIR)\Genarm.obj"
	-@erase "$(INTDIR)\Genc30.obj"
	-@erase "$(INTDIR)\Genffp.obj"
	-@erase "$(INTDIR)\Genicode.obj"
	-@erase "$(INTDIR)\Genieee.obj"
	-@erase "$(INTDIR)\Genppc.obj"
	-@erase "$(INTDIR)\Genstmt.obj"
	-@erase "$(INTDIR)\Genutil.obj"
	-@erase "$(INTDIR)\Getsym.obj"
	-@erase "$(INTDIR)\Init.obj"
	-@erase "$(INTDIR)\Intexpr.obj"
	-@erase "$(INTDIR)\List.obj"
	-@erase "$(INTDIR)\Memmgt.obj"
	-@erase "$(INTDIR)\Msgout.obj"
	-@erase "$(INTDIR)\Optimize.obj"
	-@erase "$(INTDIR)\Out68k_a.obj"
	-@erase "$(INTDIR)\Out68k_c.obj"
	-@erase "$(INTDIR)\Out68k_g.obj"
	-@erase "$(INTDIR)\Out68k_q.obj"
	-@erase "$(INTDIR)\Outarm_o.obj"
	-@erase "$(INTDIR)\Outc30_r.obj"
	-@erase "$(INTDIR)\Outgen.obj"
	-@erase "$(INTDIR)\Outppc.obj"
	-@erase "$(INTDIR)\Outx86_a.obj"
	-@erase "$(INTDIR)\Outx86_b.obj"
	-@erase "$(INTDIR)\Outx86_g.obj"
	-@erase "$(INTDIR)\Outx86_s.obj"
	-@erase "$(INTDIR)\Peep68k.obj"
	-@erase "$(INTDIR)\Peeparm.obj"
	-@erase "$(INTDIR)\Peepc30.obj"
	-@erase "$(INTDIR)\Peepppc.obj"
	-@erase "$(INTDIR)\Peepx86.obj"
	-@erase "$(INTDIR)\Reg68k.obj"
	-@erase "$(INTDIR)\Regarm.obj"
	-@erase "$(INTDIR)\Regc30.obj"
	-@erase "$(INTDIR)\Regppc.obj"
	-@erase "$(INTDIR)\Regx86.obj"
	-@erase "$(INTDIR)\Stmt.obj"
	-@erase "$(INTDIR)\Symbol.obj"
	-@erase "$(INTDIR)\System.obj"
	-@erase "$(INTDIR)\Types.obj"
	-@erase "$(OUTDIR)\c86.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /I "\DJW\PSION\SRC\C86" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "__STDC__" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /I "\DJW\PSION\SRC\C86" /D "NDEBUG" /D "WIN32"\
 /D "_CONSOLE" /D "__STDC__" /Fp"$(INTDIR)/c86.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/c86.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/c86.pdb" /machine:I386 /out:"$(OUTDIR)/c86.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Analyze.obj" \
	"$(INTDIR)\Cglbdef.obj" \
	"$(INTDIR)\Cmain.obj" \
	"$(INTDIR)\Decl.obj" \
	"$(INTDIR)\Expr.obj" \
	"$(INTDIR)\Extern.obj" \
	"$(INTDIR)\Gen386.obj" \
	"$(INTDIR)\Gen68k.obj" \
	"$(INTDIR)\Gen86.obj" \
	"$(INTDIR)\Genarm.obj" \
	"$(INTDIR)\Genc30.obj" \
	"$(INTDIR)\Genffp.obj" \
	"$(INTDIR)\Genicode.obj" \
	"$(INTDIR)\Genieee.obj" \
	"$(INTDIR)\Genppc.obj" \
	"$(INTDIR)\Genstmt.obj" \
	"$(INTDIR)\Genutil.obj" \
	"$(INTDIR)\Getsym.obj" \
	"$(INTDIR)\Init.obj" \
	"$(INTDIR)\Intexpr.obj" \
	"$(INTDIR)\List.obj" \
	"$(INTDIR)\Memmgt.obj" \
	"$(INTDIR)\Msgout.obj" \
	"$(INTDIR)\Optimize.obj" \
	"$(INTDIR)\Out68k_a.obj" \
	"$(INTDIR)\Out68k_c.obj" \
	"$(INTDIR)\Out68k_g.obj" \
	"$(INTDIR)\Out68k_q.obj" \
	"$(INTDIR)\Outarm_o.obj" \
	"$(INTDIR)\Outc30_r.obj" \
	"$(INTDIR)\Outgen.obj" \
	"$(INTDIR)\Outppc.obj" \
	"$(INTDIR)\Outx86_a.obj" \
	"$(INTDIR)\Outx86_b.obj" \
	"$(INTDIR)\Outx86_g.obj" \
	"$(INTDIR)\Outx86_s.obj" \
	"$(INTDIR)\Peep68k.obj" \
	"$(INTDIR)\Peeparm.obj" \
	"$(INTDIR)\Peepc30.obj" \
	"$(INTDIR)\Peepppc.obj" \
	"$(INTDIR)\Peepx86.obj" \
	"$(INTDIR)\Reg68k.obj" \
	"$(INTDIR)\Regarm.obj" \
	"$(INTDIR)\Regc30.obj" \
	"$(INTDIR)\Regppc.obj" \
	"$(INTDIR)\Regx86.obj" \
	"$(INTDIR)\Stmt.obj" \
	"$(INTDIR)\Symbol.obj" \
	"$(INTDIR)\System.obj" \
	"$(INTDIR)\Types.obj"

"$(OUTDIR)\c86.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\c86.exe" "$(OUTDIR)\c86.bsc"

CLEAN : 
	-@erase "$(INTDIR)\Analyze.obj"
	-@erase "$(INTDIR)\Analyze.sbr"
	-@erase "$(INTDIR)\Cglbdef.obj"
	-@erase "$(INTDIR)\Cglbdef.sbr"
	-@erase "$(INTDIR)\Cmain.obj"
	-@erase "$(INTDIR)\Cmain.sbr"
	-@erase "$(INTDIR)\Decl.obj"
	-@erase "$(INTDIR)\Decl.sbr"
	-@erase "$(INTDIR)\Expr.obj"
	-@erase "$(INTDIR)\Expr.sbr"
	-@erase "$(INTDIR)\Extern.obj"
	-@erase "$(INTDIR)\Extern.sbr"
	-@erase "$(INTDIR)\Gen386.obj"
	-@erase "$(INTDIR)\Gen386.sbr"
	-@erase "$(INTDIR)\Gen68k.obj"
	-@erase "$(INTDIR)\Gen68k.sbr"
	-@erase "$(INTDIR)\Gen86.obj"
	-@erase "$(INTDIR)\Gen86.sbr"
	-@erase "$(INTDIR)\Genarm.obj"
	-@erase "$(INTDIR)\Genarm.sbr"
	-@erase "$(INTDIR)\Genc30.obj"
	-@erase "$(INTDIR)\Genc30.sbr"
	-@erase "$(INTDIR)\Genffp.obj"
	-@erase "$(INTDIR)\Genffp.sbr"
	-@erase "$(INTDIR)\Genicode.obj"
	-@erase "$(INTDIR)\Genicode.sbr"
	-@erase "$(INTDIR)\Genieee.obj"
	-@erase "$(INTDIR)\Genieee.sbr"
	-@erase "$(INTDIR)\Genppc.obj"
	-@erase "$(INTDIR)\Genppc.sbr"
	-@erase "$(INTDIR)\Genstmt.obj"
	-@erase "$(INTDIR)\Genstmt.sbr"
	-@erase "$(INTDIR)\Genutil.obj"
	-@erase "$(INTDIR)\Genutil.sbr"
	-@erase "$(INTDIR)\Getsym.obj"
	-@erase "$(INTDIR)\Getsym.sbr"
	-@erase "$(INTDIR)\Init.obj"
	-@erase "$(INTDIR)\Init.sbr"
	-@erase "$(INTDIR)\Intexpr.obj"
	-@erase "$(INTDIR)\Intexpr.sbr"
	-@erase "$(INTDIR)\List.obj"
	-@erase "$(INTDIR)\List.sbr"
	-@erase "$(INTDIR)\Memmgt.obj"
	-@erase "$(INTDIR)\Memmgt.sbr"
	-@erase "$(INTDIR)\Msgout.obj"
	-@erase "$(INTDIR)\Msgout.sbr"
	-@erase "$(INTDIR)\Optimize.obj"
	-@erase "$(INTDIR)\Optimize.sbr"
	-@erase "$(INTDIR)\Out68k_a.obj"
	-@erase "$(INTDIR)\Out68k_a.sbr"
	-@erase "$(INTDIR)\Out68k_c.obj"
	-@erase "$(INTDIR)\Out68k_c.sbr"
	-@erase "$(INTDIR)\Out68k_g.obj"
	-@erase "$(INTDIR)\Out68k_g.sbr"
	-@erase "$(INTDIR)\Out68k_q.obj"
	-@erase "$(INTDIR)\Out68k_q.sbr"
	-@erase "$(INTDIR)\Outarm_o.obj"
	-@erase "$(INTDIR)\Outarm_o.sbr"
	-@erase "$(INTDIR)\Outc30_r.obj"
	-@erase "$(INTDIR)\Outc30_r.sbr"
	-@erase "$(INTDIR)\Outgen.obj"
	-@erase "$(INTDIR)\Outgen.sbr"
	-@erase "$(INTDIR)\Outppc.obj"
	-@erase "$(INTDIR)\Outppc.sbr"
	-@erase "$(INTDIR)\Outx86_a.obj"
	-@erase "$(INTDIR)\Outx86_a.sbr"
	-@erase "$(INTDIR)\Outx86_b.obj"
	-@erase "$(INTDIR)\Outx86_b.sbr"
	-@erase "$(INTDIR)\Outx86_g.obj"
	-@erase "$(INTDIR)\Outx86_g.sbr"
	-@erase "$(INTDIR)\Outx86_s.obj"
	-@erase "$(INTDIR)\Outx86_s.sbr"
	-@erase "$(INTDIR)\Peep68k.obj"
	-@erase "$(INTDIR)\Peep68k.sbr"
	-@erase "$(INTDIR)\Peeparm.obj"
	-@erase "$(INTDIR)\Peeparm.sbr"
	-@erase "$(INTDIR)\Peepc30.obj"
	-@erase "$(INTDIR)\Peepc30.sbr"
	-@erase "$(INTDIR)\Peepppc.obj"
	-@erase "$(INTDIR)\Peepppc.sbr"
	-@erase "$(INTDIR)\Peepx86.obj"
	-@erase "$(INTDIR)\Peepx86.sbr"
	-@erase "$(INTDIR)\Reg68k.obj"
	-@erase "$(INTDIR)\Reg68k.sbr"
	-@erase "$(INTDIR)\Regarm.obj"
	-@erase "$(INTDIR)\Regarm.sbr"
	-@erase "$(INTDIR)\Regc30.obj"
	-@erase "$(INTDIR)\Regc30.sbr"
	-@erase "$(INTDIR)\Regppc.obj"
	-@erase "$(INTDIR)\Regppc.sbr"
	-@erase "$(INTDIR)\Regx86.obj"
	-@erase "$(INTDIR)\Regx86.sbr"
	-@erase "$(INTDIR)\Stmt.obj"
	-@erase "$(INTDIR)\Stmt.sbr"
	-@erase "$(INTDIR)\Symbol.obj"
	-@erase "$(INTDIR)\Symbol.sbr"
	-@erase "$(INTDIR)\System.obj"
	-@erase "$(INTDIR)\System.sbr"
	-@erase "$(INTDIR)\Types.obj"
	-@erase "$(INTDIR)\Types.sbr"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\c86.bsc"
	-@erase "$(OUTDIR)\c86.exe"
	-@erase "$(OUTDIR)\c86.ilk"
	-@erase "$(OUTDIR)\c86.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "\DJW\PSION\SRC\C86" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "__STDC__" /FR /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /I "\DJW\PSION\SRC\C86" /D "_DEBUG"\
 /D "WIN32" /D "_CONSOLE" /D "__STDC__" /FR"$(INTDIR)/" /Fp"$(INTDIR)/c86.pch"\
 /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/c86.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Analyze.sbr" \
	"$(INTDIR)\Cglbdef.sbr" \
	"$(INTDIR)\Cmain.sbr" \
	"$(INTDIR)\Decl.sbr" \
	"$(INTDIR)\Expr.sbr" \
	"$(INTDIR)\Extern.sbr" \
	"$(INTDIR)\Gen386.sbr" \
	"$(INTDIR)\Gen68k.sbr" \
	"$(INTDIR)\Gen86.sbr" \
	"$(INTDIR)\Genarm.sbr" \
	"$(INTDIR)\Genc30.sbr" \
	"$(INTDIR)\Genffp.sbr" \
	"$(INTDIR)\Genicode.sbr" \
	"$(INTDIR)\Genieee.sbr" \
	"$(INTDIR)\Genppc.sbr" \
	"$(INTDIR)\Genstmt.sbr" \
	"$(INTDIR)\Genutil.sbr" \
	"$(INTDIR)\Getsym.sbr" \
	"$(INTDIR)\Init.sbr" \
	"$(INTDIR)\Intexpr.sbr" \
	"$(INTDIR)\List.sbr" \
	"$(INTDIR)\Memmgt.sbr" \
	"$(INTDIR)\Msgout.sbr" \
	"$(INTDIR)\Optimize.sbr" \
	"$(INTDIR)\Out68k_a.sbr" \
	"$(INTDIR)\Out68k_c.sbr" \
	"$(INTDIR)\Out68k_g.sbr" \
	"$(INTDIR)\Out68k_q.sbr" \
	"$(INTDIR)\Outarm_o.sbr" \
	"$(INTDIR)\Outc30_r.sbr" \
	"$(INTDIR)\Outgen.sbr" \
	"$(INTDIR)\Outppc.sbr" \
	"$(INTDIR)\Outx86_a.sbr" \
	"$(INTDIR)\Outx86_b.sbr" \
	"$(INTDIR)\Outx86_g.sbr" \
	"$(INTDIR)\Outx86_s.sbr" \
	"$(INTDIR)\Peep68k.sbr" \
	"$(INTDIR)\Peeparm.sbr" \
	"$(INTDIR)\Peepc30.sbr" \
	"$(INTDIR)\Peepppc.sbr" \
	"$(INTDIR)\Peepx86.sbr" \
	"$(INTDIR)\Reg68k.sbr" \
	"$(INTDIR)\Regarm.sbr" \
	"$(INTDIR)\Regc30.sbr" \
	"$(INTDIR)\Regppc.sbr" \
	"$(INTDIR)\Regx86.sbr" \
	"$(INTDIR)\Stmt.sbr" \
	"$(INTDIR)\Symbol.sbr" \
	"$(INTDIR)\System.sbr" \
	"$(INTDIR)\Types.sbr"

"$(OUTDIR)\c86.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib\
 odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/c86.pdb" /debug /machine:I386 /out:"$(OUTDIR)/c86.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Analyze.obj" \
	"$(INTDIR)\Cglbdef.obj" \
	"$(INTDIR)\Cmain.obj" \
	"$(INTDIR)\Decl.obj" \
	"$(INTDIR)\Expr.obj" \
	"$(INTDIR)\Extern.obj" \
	"$(INTDIR)\Gen386.obj" \
	"$(INTDIR)\Gen68k.obj" \
	"$(INTDIR)\Gen86.obj" \
	"$(INTDIR)\Genarm.obj" \
	"$(INTDIR)\Genc30.obj" \
	"$(INTDIR)\Genffp.obj" \
	"$(INTDIR)\Genicode.obj" \
	"$(INTDIR)\Genieee.obj" \
	"$(INTDIR)\Genppc.obj" \
	"$(INTDIR)\Genstmt.obj" \
	"$(INTDIR)\Genutil.obj" \
	"$(INTDIR)\Getsym.obj" \
	"$(INTDIR)\Init.obj" \
	"$(INTDIR)\Intexpr.obj" \
	"$(INTDIR)\List.obj" \
	"$(INTDIR)\Memmgt.obj" \
	"$(INTDIR)\Msgout.obj" \
	"$(INTDIR)\Optimize.obj" \
	"$(INTDIR)\Out68k_a.obj" \
	"$(INTDIR)\Out68k_c.obj" \
	"$(INTDIR)\Out68k_g.obj" \
	"$(INTDIR)\Out68k_q.obj" \
	"$(INTDIR)\Outarm_o.obj" \
	"$(INTDIR)\Outc30_r.obj" \
	"$(INTDIR)\Outgen.obj" \
	"$(INTDIR)\Outppc.obj" \
	"$(INTDIR)\Outx86_a.obj" \
	"$(INTDIR)\Outx86_b.obj" \
	"$(INTDIR)\Outx86_g.obj" \
	"$(INTDIR)\Outx86_s.obj" \
	"$(INTDIR)\Peep68k.obj" \
	"$(INTDIR)\Peeparm.obj" \
	"$(INTDIR)\Peepc30.obj" \
	"$(INTDIR)\Peepppc.obj" \
	"$(INTDIR)\Peepx86.obj" \
	"$(INTDIR)\Reg68k.obj" \
	"$(INTDIR)\Regarm.obj" \
	"$(INTDIR)\Regc30.obj" \
	"$(INTDIR)\Regppc.obj" \
	"$(INTDIR)\Regx86.obj" \
	"$(INTDIR)\Stmt.obj" \
	"$(INTDIR)\Symbol.obj" \
	"$(INTDIR)\System.obj" \
	"$(INTDIR)\Types.obj"

"$(OUTDIR)\c86.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "c86 - Win32 Release"
# Name "c86 - Win32 Debug"

!IF  "$(CFG)" == "c86 - Win32 Release"

!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\Analyze.c

!IF  "$(CFG)" == "c86 - Win32 Release"

DEP_CPP_ANALY=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

"$(INTDIR)\Analyze.obj" : $(SOURCE) $(DEP_CPP_ANALY) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

DEP_CPP_ANALY=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

"$(INTDIR)\Analyze.obj" : $(SOURCE) $(DEP_CPP_ANALY) "$(INTDIR)"

"$(INTDIR)\Analyze.sbr" : $(SOURCE) $(DEP_CPP_ANALY) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Cglbdef.c

!IF  "$(CFG)" == "c86 - Win32 Release"

DEP_CPP_CGLBD=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	".\version.h"\
	

"$(INTDIR)\Cglbdef.obj" : $(SOURCE) $(DEP_CPP_CGLBD) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

DEP_CPP_CGLBD=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	".\version.h"\
	

"$(INTDIR)\Cglbdef.obj" : $(SOURCE) $(DEP_CPP_CGLBD) "$(INTDIR)"

"$(INTDIR)\Cglbdef.sbr" : $(SOURCE) $(DEP_CPP_CGLBD) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Cmain.c

!IF  "$(CFG)" == "c86 - Win32 Release"

DEP_CPP_CMAIN=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	".\version.h"\
	

"$(INTDIR)\Cmain.obj" : $(SOURCE) $(DEP_CPP_CMAIN) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

DEP_CPP_CMAIN=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	".\version.h"\
	

"$(INTDIR)\Cmain.obj" : $(SOURCE) $(DEP_CPP_CMAIN) "$(INTDIR)"

"$(INTDIR)\Cmain.sbr" : $(SOURCE) $(DEP_CPP_CMAIN) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Decl.c

!IF  "$(CFG)" == "c86 - Win32 Release"

DEP_CPP_DECL_=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

"$(INTDIR)\Decl.obj" : $(SOURCE) $(DEP_CPP_DECL_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

DEP_CPP_DECL_=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

"$(INTDIR)\Decl.obj" : $(SOURCE) $(DEP_CPP_DECL_) "$(INTDIR)"

"$(INTDIR)\Decl.sbr" : $(SOURCE) $(DEP_CPP_DECL_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Expr.c

!IF  "$(CFG)" == "c86 - Win32 Release"

DEP_CPP_EXPR_=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

"$(INTDIR)\Expr.obj" : $(SOURCE) $(DEP_CPP_EXPR_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

DEP_CPP_EXPR_=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

"$(INTDIR)\Expr.obj" : $(SOURCE) $(DEP_CPP_EXPR_) "$(INTDIR)"

"$(INTDIR)\Expr.sbr" : $(SOURCE) $(DEP_CPP_EXPR_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Extern.c

!IF  "$(CFG)" == "c86 - Win32 Release"

DEP_CPP_EXTER=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

"$(INTDIR)\Extern.obj" : $(SOURCE) $(DEP_CPP_EXTER) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

DEP_CPP_EXTER=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

"$(INTDIR)\Extern.obj" : $(SOURCE) $(DEP_CPP_EXTER) "$(INTDIR)"

"$(INTDIR)\Extern.sbr" : $(SOURCE) $(DEP_CPP_EXTER) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Gen386.c

!IF  "$(CFG)" == "c86 - Win32 Release"

DEP_CPP_GEN38=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen386.h"\
	".\genx86.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

"$(INTDIR)\Gen386.obj" : $(SOURCE) $(DEP_CPP_GEN38) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

DEP_CPP_GEN38=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen386.h"\
	".\genx86.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

"$(INTDIR)\Gen386.obj" : $(SOURCE) $(DEP_CPP_GEN38) "$(INTDIR)"

"$(INTDIR)\Gen386.sbr" : $(SOURCE) $(DEP_CPP_GEN38) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Gen68k.c

!IF  "$(CFG)" == "c86 - Win32 Release"

DEP_CPP_GEN68=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen68k.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

"$(INTDIR)\Gen68k.obj" : $(SOURCE) $(DEP_CPP_GEN68) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"

DEP_CPP_GEN68=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen68k.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

"$(INTDIR)\Gen68k.obj" : $(SOURCE) $(DEP_CPP_GEN68) "$(INTDIR)"

"$(INTDIR)\Gen68k.sbr" : $(SOURCE) $(DEP_CPP_GEN68) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Gen86.c
DEP_CPP_GEN86=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen86.h"\
	".\genx86.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Gen86.obj" : $(SOURCE) $(DEP_CPP_GEN86) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Gen86.obj" : $(SOURCE) $(DEP_CPP_GEN86) "$(INTDIR)"

"$(INTDIR)\Gen86.sbr" : $(SOURCE) $(DEP_CPP_GEN86) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Genarm.c
DEP_CPP_GENAR=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genarm.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Genarm.obj" : $(SOURCE) $(DEP_CPP_GENAR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Genarm.obj" : $(SOURCE) $(DEP_CPP_GENAR) "$(INTDIR)"

"$(INTDIR)\Genarm.sbr" : $(SOURCE) $(DEP_CPP_GENAR) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Genc30.c
DEP_CPP_GENC3=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genc30.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Genc30.obj" : $(SOURCE) $(DEP_CPP_GENC3) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Genc30.obj" : $(SOURCE) $(DEP_CPP_GENC3) "$(INTDIR)"

"$(INTDIR)\Genc30.sbr" : $(SOURCE) $(DEP_CPP_GENC3) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Genffp.c
DEP_CPP_GENFF=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Genffp.obj" : $(SOURCE) $(DEP_CPP_GENFF) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Genffp.obj" : $(SOURCE) $(DEP_CPP_GENFF) "$(INTDIR)"

"$(INTDIR)\Genffp.sbr" : $(SOURCE) $(DEP_CPP_GENFF) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Genicode.c
DEP_CPP_GENIC=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Genicode.obj" : $(SOURCE) $(DEP_CPP_GENIC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Genicode.obj" : $(SOURCE) $(DEP_CPP_GENIC) "$(INTDIR)"

"$(INTDIR)\Genicode.sbr" : $(SOURCE) $(DEP_CPP_GENIC) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Genieee.c
DEP_CPP_GENIE=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Genieee.obj" : $(SOURCE) $(DEP_CPP_GENIE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Genieee.obj" : $(SOURCE) $(DEP_CPP_GENIE) "$(INTDIR)"

"$(INTDIR)\Genieee.sbr" : $(SOURCE) $(DEP_CPP_GENIE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Genppc.c
DEP_CPP_GENPP=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genppc.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Genppc.obj" : $(SOURCE) $(DEP_CPP_GENPP) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Genppc.obj" : $(SOURCE) $(DEP_CPP_GENPP) "$(INTDIR)"

"$(INTDIR)\Genppc.sbr" : $(SOURCE) $(DEP_CPP_GENPP) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Genstmt.c
DEP_CPP_GENST=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Genstmt.obj" : $(SOURCE) $(DEP_CPP_GENST) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Genstmt.obj" : $(SOURCE) $(DEP_CPP_GENST) "$(INTDIR)"

"$(INTDIR)\Genstmt.sbr" : $(SOURCE) $(DEP_CPP_GENST) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Genutil.c
DEP_CPP_GENUT=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Genutil.obj" : $(SOURCE) $(DEP_CPP_GENUT) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Genutil.obj" : $(SOURCE) $(DEP_CPP_GENUT) "$(INTDIR)"

"$(INTDIR)\Genutil.sbr" : $(SOURCE) $(DEP_CPP_GENUT) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Getsym.c
DEP_CPP_GETSY=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Getsym.obj" : $(SOURCE) $(DEP_CPP_GETSY) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Getsym.obj" : $(SOURCE) $(DEP_CPP_GETSY) "$(INTDIR)"

"$(INTDIR)\Getsym.sbr" : $(SOURCE) $(DEP_CPP_GETSY) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Init.c
DEP_CPP_INIT_=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Init.obj" : $(SOURCE) $(DEP_CPP_INIT_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Init.obj" : $(SOURCE) $(DEP_CPP_INIT_) "$(INTDIR)"

"$(INTDIR)\Init.sbr" : $(SOURCE) $(DEP_CPP_INIT_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Intexpr.c
DEP_CPP_INTEX=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Intexpr.obj" : $(SOURCE) $(DEP_CPP_INTEX) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Intexpr.obj" : $(SOURCE) $(DEP_CPP_INTEX) "$(INTDIR)"

"$(INTDIR)\Intexpr.sbr" : $(SOURCE) $(DEP_CPP_INTEX) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\List.c
DEP_CPP_LIST_=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\List.obj" : $(SOURCE) $(DEP_CPP_LIST_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\List.obj" : $(SOURCE) $(DEP_CPP_LIST_) "$(INTDIR)"

"$(INTDIR)\List.sbr" : $(SOURCE) $(DEP_CPP_LIST_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Memmgt.c
DEP_CPP_MEMMG=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Memmgt.obj" : $(SOURCE) $(DEP_CPP_MEMMG) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Memmgt.obj" : $(SOURCE) $(DEP_CPP_MEMMG) "$(INTDIR)"

"$(INTDIR)\Memmgt.sbr" : $(SOURCE) $(DEP_CPP_MEMMG) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Msgout.c
DEP_CPP_MSGOU=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Msgout.obj" : $(SOURCE) $(DEP_CPP_MSGOU) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Msgout.obj" : $(SOURCE) $(DEP_CPP_MSGOU) "$(INTDIR)"

"$(INTDIR)\Msgout.sbr" : $(SOURCE) $(DEP_CPP_MSGOU) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Optimize.c
DEP_CPP_OPTIM=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Optimize.obj" : $(SOURCE) $(DEP_CPP_OPTIM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Optimize.obj" : $(SOURCE) $(DEP_CPP_OPTIM) "$(INTDIR)"

"$(INTDIR)\Optimize.sbr" : $(SOURCE) $(DEP_CPP_OPTIM) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Out68k_a.c
DEP_CPP_OUT68=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen68k.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Out68k_a.obj" : $(SOURCE) $(DEP_CPP_OUT68) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Out68k_a.obj" : $(SOURCE) $(DEP_CPP_OUT68) "$(INTDIR)"

"$(INTDIR)\Out68k_a.sbr" : $(SOURCE) $(DEP_CPP_OUT68) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Out68k_c.c
DEP_CPP_OUT68K=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen68k.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Out68k_c.obj" : $(SOURCE) $(DEP_CPP_OUT68K) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Out68k_c.obj" : $(SOURCE) $(DEP_CPP_OUT68K) "$(INTDIR)"

"$(INTDIR)\Out68k_c.sbr" : $(SOURCE) $(DEP_CPP_OUT68K) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Out68k_g.c
DEP_CPP_OUT68K_=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen68k.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Out68k_g.obj" : $(SOURCE) $(DEP_CPP_OUT68K_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Out68k_g.obj" : $(SOURCE) $(DEP_CPP_OUT68K_) "$(INTDIR)"

"$(INTDIR)\Out68k_g.sbr" : $(SOURCE) $(DEP_CPP_OUT68K_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Out68k_q.c
DEP_CPP_OUT68K_Q=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen68k.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Out68k_q.obj" : $(SOURCE) $(DEP_CPP_OUT68K_Q) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Out68k_q.obj" : $(SOURCE) $(DEP_CPP_OUT68K_Q) "$(INTDIR)"

"$(INTDIR)\Out68k_q.sbr" : $(SOURCE) $(DEP_CPP_OUT68K_Q) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Outarm_o.c
DEP_CPP_OUTAR=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genarm.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Outarm_o.obj" : $(SOURCE) $(DEP_CPP_OUTAR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Outarm_o.obj" : $(SOURCE) $(DEP_CPP_OUTAR) "$(INTDIR)"

"$(INTDIR)\Outarm_o.sbr" : $(SOURCE) $(DEP_CPP_OUTAR) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Outc30_r.c
DEP_CPP_OUTC3=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genc30.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Outc30_r.obj" : $(SOURCE) $(DEP_CPP_OUTC3) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Outc30_r.obj" : $(SOURCE) $(DEP_CPP_OUTC3) "$(INTDIR)"

"$(INTDIR)\Outc30_r.sbr" : $(SOURCE) $(DEP_CPP_OUTC3) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Outgen.c
DEP_CPP_OUTGE=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Outgen.obj" : $(SOURCE) $(DEP_CPP_OUTGE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Outgen.obj" : $(SOURCE) $(DEP_CPP_OUTGE) "$(INTDIR)"

"$(INTDIR)\Outgen.sbr" : $(SOURCE) $(DEP_CPP_OUTGE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Outppc.c
DEP_CPP_OUTPP=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genppc.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Outppc.obj" : $(SOURCE) $(DEP_CPP_OUTPP) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Outppc.obj" : $(SOURCE) $(DEP_CPP_OUTPP) "$(INTDIR)"

"$(INTDIR)\Outppc.sbr" : $(SOURCE) $(DEP_CPP_OUTPP) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Outx86_a.c
DEP_CPP_OUTX8=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genx86.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Outx86_a.obj" : $(SOURCE) $(DEP_CPP_OUTX8) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Outx86_a.obj" : $(SOURCE) $(DEP_CPP_OUTX8) "$(INTDIR)"

"$(INTDIR)\Outx86_a.sbr" : $(SOURCE) $(DEP_CPP_OUTX8) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Outx86_b.c
DEP_CPP_OUTX86=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genx86.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Outx86_b.obj" : $(SOURCE) $(DEP_CPP_OUTX86) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Outx86_b.obj" : $(SOURCE) $(DEP_CPP_OUTX86) "$(INTDIR)"

"$(INTDIR)\Outx86_b.sbr" : $(SOURCE) $(DEP_CPP_OUTX86) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Outx86_g.c
DEP_CPP_OUTX86_=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genx86.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Outx86_g.obj" : $(SOURCE) $(DEP_CPP_OUTX86_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Outx86_g.obj" : $(SOURCE) $(DEP_CPP_OUTX86_) "$(INTDIR)"

"$(INTDIR)\Outx86_g.sbr" : $(SOURCE) $(DEP_CPP_OUTX86_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Outx86_s.c
DEP_CPP_OUTX86_S=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genx86.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	".\version.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Outx86_s.obj" : $(SOURCE) $(DEP_CPP_OUTX86_S) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Outx86_s.obj" : $(SOURCE) $(DEP_CPP_OUTX86_S) "$(INTDIR)"

"$(INTDIR)\Outx86_s.sbr" : $(SOURCE) $(DEP_CPP_OUTX86_S) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Peep68k.c
DEP_CPP_PEEP6=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen68k.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Peep68k.obj" : $(SOURCE) $(DEP_CPP_PEEP6) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Peep68k.obj" : $(SOURCE) $(DEP_CPP_PEEP6) "$(INTDIR)"

"$(INTDIR)\Peep68k.sbr" : $(SOURCE) $(DEP_CPP_PEEP6) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Peeparm.c
DEP_CPP_PEEPA=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genarm.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Peeparm.obj" : $(SOURCE) $(DEP_CPP_PEEPA) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Peeparm.obj" : $(SOURCE) $(DEP_CPP_PEEPA) "$(INTDIR)"

"$(INTDIR)\Peeparm.sbr" : $(SOURCE) $(DEP_CPP_PEEPA) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Peepc30.c
DEP_CPP_PEEPC=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genc30.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Peepc30.obj" : $(SOURCE) $(DEP_CPP_PEEPC) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Peepc30.obj" : $(SOURCE) $(DEP_CPP_PEEPC) "$(INTDIR)"

"$(INTDIR)\Peepc30.sbr" : $(SOURCE) $(DEP_CPP_PEEPC) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Peepppc.c
DEP_CPP_PEEPP=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genppc.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Peepppc.obj" : $(SOURCE) $(DEP_CPP_PEEPP) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Peepppc.obj" : $(SOURCE) $(DEP_CPP_PEEPP) "$(INTDIR)"

"$(INTDIR)\Peepppc.sbr" : $(SOURCE) $(DEP_CPP_PEEPP) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Peepx86.c
DEP_CPP_PEEPX=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genx86.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Peepx86.obj" : $(SOURCE) $(DEP_CPP_PEEPX) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Peepx86.obj" : $(SOURCE) $(DEP_CPP_PEEPX) "$(INTDIR)"

"$(INTDIR)\Peepx86.sbr" : $(SOURCE) $(DEP_CPP_PEEPX) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Reg68k.c
DEP_CPP_REG68=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\gen68k.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Reg68k.obj" : $(SOURCE) $(DEP_CPP_REG68) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Reg68k.obj" : $(SOURCE) $(DEP_CPP_REG68) "$(INTDIR)"

"$(INTDIR)\Reg68k.sbr" : $(SOURCE) $(DEP_CPP_REG68) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Regarm.c
DEP_CPP_REGAR=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genarm.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Regarm.obj" : $(SOURCE) $(DEP_CPP_REGAR) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Regarm.obj" : $(SOURCE) $(DEP_CPP_REGAR) "$(INTDIR)"

"$(INTDIR)\Regarm.sbr" : $(SOURCE) $(DEP_CPP_REGAR) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Regc30.c
DEP_CPP_REGC3=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genc30.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Regc30.obj" : $(SOURCE) $(DEP_CPP_REGC3) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Regc30.obj" : $(SOURCE) $(DEP_CPP_REGC3) "$(INTDIR)"

"$(INTDIR)\Regc30.sbr" : $(SOURCE) $(DEP_CPP_REGC3) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Regppc.c
DEP_CPP_REGPP=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genppc.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Regppc.obj" : $(SOURCE) $(DEP_CPP_REGPP) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Regppc.obj" : $(SOURCE) $(DEP_CPP_REGPP) "$(INTDIR)"

"$(INTDIR)\Regppc.sbr" : $(SOURCE) $(DEP_CPP_REGPP) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Regx86.c
DEP_CPP_REGX8=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\genx86.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Regx86.obj" : $(SOURCE) $(DEP_CPP_REGX8) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Regx86.obj" : $(SOURCE) $(DEP_CPP_REGX8) "$(INTDIR)"

"$(INTDIR)\Regx86.sbr" : $(SOURCE) $(DEP_CPP_REGX8) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Stmt.c
DEP_CPP_STMT_=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Stmt.obj" : $(SOURCE) $(DEP_CPP_STMT_) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Stmt.obj" : $(SOURCE) $(DEP_CPP_STMT_) "$(INTDIR)"

"$(INTDIR)\Stmt.sbr" : $(SOURCE) $(DEP_CPP_STMT_) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Symbol.c
DEP_CPP_SYMBO=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\outproto.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Symbol.obj" : $(SOURCE) $(DEP_CPP_SYMBO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Symbol.obj" : $(SOURCE) $(DEP_CPP_SYMBO) "$(INTDIR)"

"$(INTDIR)\Symbol.sbr" : $(SOURCE) $(DEP_CPP_SYMBO) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\System.c
DEP_CPP_SYSTE=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	".\version.h"\
	
NODEP_CPP_SYSTE=\
	".\cpoclib.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\System.obj" : $(SOURCE) $(DEP_CPP_SYSTE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\System.obj" : $(SOURCE) $(DEP_CPP_SYSTE) "$(INTDIR)"

"$(INTDIR)\System.sbr" : $(SOURCE) $(DEP_CPP_SYSTE) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Types.c
DEP_CPP_TYPES=\
	".\c86.rsg"\
	".\cglbdec.h"\
	".\chdr.h"\
	".\check.h"\
	".\config.h"\
	".\expr.h"\
	".\message.h"\
	".\proto.h"\
	

!IF  "$(CFG)" == "c86 - Win32 Release"


"$(INTDIR)\Types.obj" : $(SOURCE) $(DEP_CPP_TYPES) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "c86 - Win32 Debug"


"$(INTDIR)\Types.obj" : $(SOURCE) $(DEP_CPP_TYPES) "$(INTDIR)"

"$(INTDIR)\Types.sbr" : $(SOURCE) $(DEP_CPP_TYPES) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
