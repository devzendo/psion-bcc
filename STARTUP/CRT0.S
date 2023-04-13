| Startup code for .img files created by bcc
| Taken from CPOC by Matt Gumbley

FilConnect	equ	0x87
ProcId		equ	0x88
ProcKill	equ	0x88


	.text
	.extern _main
	entry	_start

_start:
	call	begin
	retf

begin:	
	| Synchronous connection to the file server
	sub	al, al
	mov	ah, #0
	int	FilConnect
	jb	p_abort

	call	InitLoop

L1:
	| Get the current Process
	mov	ah, #0
	int	ProcId

	| Kill process with result code [Result]
	mov	bx, ax
	mov	ax, word [Result]
	mov	ah, #8
	int	ProcKill

p_abort:
	mov	al, #0xec
	mov	word [Result], ax
	jmp	L1

InitLoop:
	push	di
	push	si

	mov	word [SaveSP], bp
	mov	word [SaveBP], sp
	call	_main
	mov	word [Result], ax

	pop	si
	pop	di
	ret

	.globl	_start

	.data

|	When loaded, the magic statics (64 bytes), and the stack
|	will be automatically placed before the following data
|	by the Psion's .img file loader.


SaveSP:	.data2	0
SaveBP:	.data2	0
Result: .data2	0

