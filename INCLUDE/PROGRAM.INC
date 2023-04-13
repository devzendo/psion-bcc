        title   PROGRAM
        subttl  Copyright (c) Psion PLC 1993
        name    PROGRAM
;
;  VER    DATE    BY  DESCRIPTION
; ----- -------- ---- -----------
; 00.1A 03/03/93  HP  First release
;
PROGRAM_INC     equ     1

IFNDEF P_STD_INC
 INCLUDE ..\inc\P_STD.INC
ENDIF
IFNDEF P_FILE_INC
 INCLUDE ..\inc\P_FILE.INC
ENDIF

; Constants for progexec
PROGEXEC_SIGNAL equ (001h)
PROGEXEC_NOTIFY equ (002h)
H_COMMAND_TRANSLATE_FILE equ ('T')
H_COMMAND_RUN_FILE equ ('R')

; Constants for progtran
PT_PROGTRAN_LINE equ (010h)
PT_PROGTRAN_DEATH equ (011h)

; Types for progtran
PROGTRAN_STATUS struc
PROGTRAN_STATUSStat  dw ? 
PROGTRAN_STATUSMode  dw ? 
PROGTRAN_STATUSLine  dw ? 
PROGTRAN_STATUSOffset  dw ? 
PROGTRAN_STATUS ends
;
PROGTRAN_SOURCE struc
PROGTRAN_SOURCEPid  dw ? 
PROGTRAN_SOURCEBuffer_offset dw ?
PROGTRAN_SOURCEStatus_offset dw ?
PROGTRAN_SOURCE ends
;
PROGEXEC_RESBUF struc
PROGEXEC_RESBUFError  dw ? 
PROGEXEC_RESBUFLine  dw ? 
PROGEXEC_RESBUFOffset  dw ? 
PROGEXEC_RESBUFErr db (1) * 40 dup (?)
PROGEXEC_RESBUFSrc db (1) * P_FNAMESIZE dup (?)
PROGEXEC_RESBUF ends
PROGEXEC_PAR struc
PROGEXEC_PARFlags  dw ? 
PROGEXEC_PARPid  dw ? 
PROGEXEC_PARResult_offset dw ?
PROGEXEC_PAR ends
