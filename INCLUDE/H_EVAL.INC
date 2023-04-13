        .xlist
; Include file - H_EVAL.INC
; Epoc/Os OPL runtime include file
; Copyright (c) Psion PLC 1988.
;  VER    DATE    BY  DESCRIPTION
; ----- -------- ---- -----------
; 1.00A 04/06/91  HP  First release
;
H_EVAL_INC	equ	1
        .xlist
;
EVAL_DEFAULT_PLACES	equ 2
EVAL_DEFAULT_FMT_TYPE	equ DtobTypeFixed
CALC_MAX_PLACES		equ 12
CALC_DEFAULT_PLACES	equ CALC_MAX_PLACES
CALC_DEFAULT_FMT_TYPE	equ DtobTypeGeneral
MAX_MEMORIES 		equ 10
;
MEM_VALUES	struc
memValuesEvalFormat	db	?
memValuesEvalDPlaces	db	?
memValuesCalcFormat	db	?
memValuesCalcDPlaces	db	?
memValuesMemories	dq	MAX_MEMORIES dup (?)
MEM_VALUES	ends
;
; Memory environment variable structure (name M$V)
;
MEM_ENV	struc
memEnvNameLbc		db	?
memEnvName		db 3 dup (?)
memEnvValueLbc		db	?
memEnvValue		MEM_VALUES <>
MEM_ENV ends
;
sizeMemName = memEnvValueLbc-memEnvName	; M$V
;
EXTENDED_MEM_VALUES     struc
exMemValuesEvalDegrees  db      ?
exMemValuesCalcDegrees  db      ?
exMemValuesMemValues    MEM_VALUES <>
EXTENDED_MEM_VALUES     ends

