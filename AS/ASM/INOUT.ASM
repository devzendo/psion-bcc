	IN	EAX,DX		; plain IN is no longer allowed
	INB
	IN	AL,DX
	INW
	IN	AX,DX
	IN	EAX,DX
	IN	AL,$20
	IN	AL,$101
	IN	AX,$20
	IN	AX,$101
	IN	EAX,$20
	IN	EAX,$101

	OUTB	DX,EAX		; plain OUT is no longer allowed
	OUTB
	OUT	DX,AL
	OUTW
	OUT	DX,AX
	OUT	DX,EAX
	OUT	$20,AL
	OUT	$101,AL
	OUT	$20,AX
	OUT	#101,AX
	OUT	$20,EAX
	OUT	$101,EAX
