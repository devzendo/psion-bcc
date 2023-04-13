        .xlist
; Include file - H_FILE.INC
; Flags for Hwif file selector and editor
; Copyright (c) Psion PLC 1988.
;  VER    DATE    BY  DESCRIPTION
; ----- -------- ---- -----------
;       28/08/91  HP  First release
;
H_FILE_INC	equ	1
;
H_FILE_ALLOW_DIRS equ 02h
H_FILE_JUST_DIRS equ 04h
H_FILE_FORCE_NXIST equ 08h
H_FILE_NO_AUTOQUERY equ 10h
H_FILE_ACCEPT_NULL equ 20h
H_FILE_SET_DEFEXT equ 40h
H_FILE_CAN_WILDCARD equ 80h

H_FILE_STANDARD_INIT equ 01h
H_FILE_RESTRICT_LIST equ H_FILE_FORCE_NXIST
H_FILE_CAN_TAG equ H_FILE_NO_AUTOQUERY

H_FILE_HWIF_MASK equ 0feh
H_FILE_PICK_SELECTOR equ 0h
H_FILE_NEW_EDITOR equ 01h

H_FILE_IS_DIR equ 01h
H_FILE_AT_ROOT equ 02h
H_FILE_IS_ROOT equ 03h
