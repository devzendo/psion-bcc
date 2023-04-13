frame  =    4        (* standard stack frame, near call *)
bxframe =   2        (* bx stack frame, near call *)

PopParam = 0         (* Dummy value for changing real return convention *)
DOSHUGESHIFT = 12

(***************************** Data Type Sizes *****************************)

CodePtrSize = 2      (* Code pointer, near calls *)
DataPtrSize = 2      (* Data pointer, 16 bit data pointer models *)

_ptr     = 0         (* _iob structure *)
_cnt     = 2
_size    = 4
_base    = 6
_flag    = 8
_file    = 10
_pback   = 12
_iobSize = 14        (* size of _iob structure *)

(***************************** OS Error Codes ******************************)

EFAULT	    =  -1
ENOENT      =  -33
ENOPATH     =  -42
EMFILE	    =  -18
EACCESS     =  -39
EBADF       =  -15
E2BIG       =  -6
ENOMEM      =  -10
ENOSPC      =  -37
EINVAL      =  -2
EDOM        =  -2
ERANGE      =  -7

(***************************** IO Constants*********************************)

BUFSIZ    =    512                      (* IO Buffer size *)

_IOFBF	  =      0                      (* setvbuf - full buffering *)
_IOLBF	  =      1                      (* setvbuf - line buffering *)
_IONBF	  =      2                      (* setvbuf - no buffering *)

_F_RDWR   =   0003H			(* Read/write  *)
_F_READ   =   0001H			(* Read only file *)
_F_WRIT   =   0002H			(* Write only file *)
_F_UBUF   =   0004H			(* User allocated buffer *)
_F_APP	  =   0008H			(* Append data *)
_F_ERR	  =   0010H			(* Error *)
_F_EOF	  =   0020H			(* EOF *)
_F_BIN	  =   0040H			(* Binary file *)
_F_IN	  =   0080H			(* Data is incoming *)
_F_OUT	  =   0100H			(* Data is outgoing *)
_F_DEV	  =   0200H			(* File is terminal *)
_F_RST	  =   0400H			(* Newly opened stream *)
_F_LBUF   =   0800H			(* line buffered stream *)
_F_CTZ	  =   1000H

SEEK_SET  =      0                      (* lseek - origin beginning of file *)
SEEK_CUR  =      1                      (* lseek - origin current position *)
SEEK_END  =	 2                      (* lseek - origin end of file *)

CTLZ      =     1AH                     (* Text mode EOF character *)
EOF       =     -1                      (* end of file return value *)

O_RDONLY  =      0
O_WRONLY  =      1
O_RDWR    =      2

O_CREAT   =	0100H	                (* create and open file *)
O_TRUNC	  =	0200H	                (* open with truncation *)
O_EXCL	  =	0400H	                (* exclusive open *)

_O_EOF    =	0200H                   (* set when text file hits ^Z   *)

O_APPEND  =	0800H	                (* write to end of file *)

O_CHANGED =	1000H	                (* File has been written *)
O_DEVICE  =	2000H               	(* user read only flag	 *)
O_TEXT    =	4000H	                (* CR-LF translation	*)
O_BINARY  = 	8000H	                (* no translation	*)

SH_NOINHERIT =    80H                   (* File sharing modes *)
SH_COMPAT    =    00H
SH_DENYRW    =    10H
SH_DENYWR    =	  20H
SH_DENYRD    =    30H
SH_DENYNO    =    40H

SH_DENYNONE  =	SH_DENYNO               (* MS documentation uses both *)

S_IFDIR      =  4000H                   (* directory *)
S_IFCHR      =  2000H                   (* character device *)
S_IFREG      =  8000H                   (* regular file *)
S_IREAD      =  0100H                   (* owner may read *)
S_IWRITE     =  0080H                   (* owner may write *)
S_IEXEC      =  0040H                   (* owner may execute directory search *)

FA_NORMAL	=	 00H		(* normal file *)
FA_RDONLY	=	 01H		(* Read only attribute *)
FA_HIDDEN	=	 02H		(* Hidden file *)
FA_SYSTEM	=	 04H		(* System file *)
FA_LABEL	=	 08H		(* Volume label *)
FA_DIREC	=	 10H		(* Directory *)
FA_ARCH 	=	 20H		(* Archive *)
FA_TEXT         =	100H            (* Open in text mode *)
FA_SHARE        =	200H            (* Open with sharing *)

E_CONS		=	8000H		(* The console channel *)
E_DEVICE	=	4000H		(* Its a character device *)

(************************ OS2 structures and constants  ********************)

fdateCreation   =  0
ftimeCreation   =  2
fdateLastAccess =  4
ftimeLastAccess =  6
fdateLastWrite  =  8
ftimeLastWrite  = 10
cbFile          = 12
cbFileAlloc     = 16
attrFile        = 20

FileInfoSize    = 22

IO_WAIT   = 0
IO_NOWAIT = 1

hours       = 0
minutes     = 1
seconds     = 2
hundredths  = 3
day         = 4
month       = 5
year        = 6
timezone    = 8
weekday     = 10

DateTimeSize = 11

EXIT_THREAD      =   0
EXIT_PROCESS     =   1
EXLST_EXIT       =   3
EXLST_ADD        =   1

(* Signal Numbers for DosSetSigHandler  *)

SIG_CTRLC        =   1       (* Control C            *)
SIG_BROKENPIPE   =   2       (* Broken Pipe          *)
SIG_KILLPROCESS  =   3       (* Program Termination  *)
SIG_CTRLBREAK    =   4       (* Control Break        *)
SIG_PFLG_A       =   5       (* Process Flag A       *)
SIG_PFLG_B       =   6       (* Process Flag B       *)
SIG_PFLG_C       =   7       (* Process Flag C       *)
SIG_CSIGNALS     =   8       (* number of signals plus one *)


(* Flag Numbers for DosFlagProcess      *)

PFLG_A           =   0       (* Process Flag A       *)
PFLG_B           =   1       (* Process Flag B       *)
PFLG_C           =   2       (* Process Flag C       *)

(* Signal actions *)

SIGA_KILL        =   0
SIGA_IGNORE      =   1
SIGA_ACCEPT      =   2
SIGA_ERROR       =   3
SIGA_ACKNOWLEDGE =   4


SIG_DFL          =   0
SIG_IGN          =   1
SIG_SGE          =   3
SIG_ACK          =   4


(************************ Library Internal Constants ***********************)
(*                                                                         *)
(* These constants are internal to the run-time library and may NOT        *)
(* changed.                                                                *)
(*                                                                         *)
(***************************************************************************)

TRUE              =      1
FALSE             =      0

math_saved_regs   =      8

ExpNeg            =     80H
magic             =  01234H         (* value to flag exception handler *)
MAGIC             =  01234H         (* value to flag exception handler *)

f_st5             =     10H         (* arg1 is in st5 *)
f_two             =     20H         (* two arguments *)

_DOMAIN           =      1          (* parameter not in valid domain *)
_SING             =      2          (* function is incalculable at this place *)
_OVERFLOW         =      3          (* result exceeds representable range *)
_UNDERFLOW        =      4          (* result too close to zero to be represented *)
_TLOSS            =      5          (* total loss of precision (eg. Sine (2**65)) *)
_PLOSS            =      6          (* partial precision loss *)

ZFLAG            =      80H         (* Zero pad flag from printf *)

stream           =       0
flush            =       2
count            =       4
args             =       6
handler          =       8

InMathLib        =       0

(* Priority         =       0 *)
(* ProcVar          =       2 *)
(* InitSize	 =	 4 *)

Priority         =       2
ProcVar          =       3
InitSize	 =	 5

PR0              =       30
PR1              =       29
PR2              =       28
PR3              =       27
PR4              =       26
PR5              =       25
PRL              =       20

PRMAX            =       32

emu_fraction    = 0
emu_exponent    = 8
emu_sign        = 10
emu_spare       = 11
emu_temp_size   = 12

by0 = 0
by1 = 1

w0 = 0
w1 = 2
w2 = 4
w3 = 6

dd0 = 0
dd1 = 4

STACK_GUARD    = 1234H

GETSTATE_START =  0
GETSTATE_END   =  2
GETSTATE_FIRST =  4

_j_flag		=	0
_j_ip		=	2
_j_sp		=	4
_j_bp		=	6
_j_si		=	8
_j_di		=	10
_j_dx		=	12
_j_cx		=	14
_j_bx		=	16
_j_classHandle	=	18
_j_classPtr	=	20
_j_enterFrame	=	22
_j_osFrame	=	24
_j_st1		=	26
_j_st2		=	36

