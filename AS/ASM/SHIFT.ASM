	RCL	AL,CL
	RCL	AH,CL
	RCL	BL,CL
	RCL	BH,CL
	RCL	CL,CL
	RCL	CH,CL
	RCL	DL,CL
	RCL	DH,CL
	RCL	#1,CL		; illeg
	RCL	[BX],CL		; illeg
	RCL	BYTE [BX],CL

	RCL	AX,CL
	RCL	BX,CL
	RCL	CX,CL
	RCL	DX,CL
	RCL	SP,CL
	RCL	BP,CL
	RCL	SI,CL
	RCL	DI,CL
	RCL	CS,CL		; illeg
	RCL	DS,CL		; illeg
	RCL	ES,CL		; illeg
	RCL	FS,CL		; illeg
	RCL	GS,CL		; illeg
	RCL	WORD [BX],CL

	RCL	EAX,CL
	RCL	EBX,CL
	RCL	ECX,CL
	RCL	EDX,CL
	RCL	ESP,CL
	RCL	EBP,CL
	RCL	ESI,CL
	RCL	EDI,CL
	RCL	DWORD [BX],CL

	RCL	AL,1
	RCL	AH,1
	RCL	BL,1
	RCL	BH,1
	RCL	CL,1
	RCL	CH,1
	RCL	DL,1
	RCL	DH,1
	RCL	#1,1		; illeg
	RCL	[BX],1		; illeg
	RCL	BYTE [BX],1

	RCL	AX,1
	RCL	BX,1
	RCL	CX,1
	RCL	DX,1
	RCL	SP,1
	RCL	BP,1
	RCL	SI,1
	RCL	DI,1
	RCL	CS,1		; illeg
	RCL	DS,1		; illeg
	RCL	ES,1		; illeg
	RCL	FS,1		; illeg
	RCL	GS,1		; illeg
	RCL	WORD [BX],1

	RCL	EAX,1
	RCL	EBX,1
	RCL	ECX,1
	RCL	EDX,1
	RCL	ESP,1
	RCL	EBP,1
	RCL	ESI,1
	RCL	EDI,1
	RCL	DWORD [BX],1

	RCL	AL,15
	RCL	AH,15
	RCL	BL,15
	RCL	BH,15
	RCL	CL,15
	RCL	CH,15
	RCL	DL,15
	RCL	DH,15
	RCL	#1,15		; illeg
	RCL	[BX],15		; illeg
	RCL	BYTE [BX],15
	RCL	AL,$1000

	RCL	AX,15
	RCL	BX,15
	RCL	CX,15
	RCL	DX,15
	RCL	SP,15
	RCL	BP,15
	RCL	SI,15
	RCL	DI,15
	RCL	CS,15		; illeg
	RCL	DS,15		; illeg
	RCL	ES,15		; illeg
	RCL	FS,15		; illeg
	RCL	GS,15		; illeg
	RCL	WORD [BX],15

	RCL	EAX,15
	RCL	EBX,15
	RCL	ECX,15
	RCL	EDX,15
	RCL	ESP,15
	RCL	EBP,15
	RCL	ESI,15
	RCL	EDI,15
	RCL	DWORD [BX],15

	RCR	AX,7
	ROL	AX,7
	ROR	AX,7
	SAL	AX,7
	SAR	AX,7
	SHL	AX,7
	SHR	AX,7
