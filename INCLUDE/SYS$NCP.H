/*
SYS$NCP.H - Header file for NCP defines
*/

#define NCLINK_VERSION_NUMBER       3
#define NCLINK_MINOR_VERNO          1

/* Informational data obtained by supervisory reads */
#define PHYS_LINK_FAILED        0       /* Link layer has failed*/
#define PHYS_CONNECT_FAILED     1       /* Waiting for connection failed */
#define PHYS_CHARS_FAILED       2       /* Setting serial characteristics failed */
#define PHYS_INIT_FAILED        3       /* Initialization of modem failed */
#define PHYS_DIAL_FAILED        4       /* Dialling phone number failed */
#define PHYS_MDMCONFIG_FAILED   5       /* additional modem config failed */
#define PHYS_PHYS_LINK_ESTABLISHED 6    /* A physical link established */
#define PHYS_WAITING_FOR_CALL   7       /* Physical layer waiting for call */
#define PHYS_DIALLING_NUMBER    8       /* Physical layer dialling */
#define PHYS_CONFIGURING_MODEM  9       /* configuring modem */
#define PHYS_NCP_LINK_ESTAB_OK  10       /* Ncp link established OK */
#define PHYS_NCP_LINK_ESTAB_NEW_NCP 11  /* Talking to different Ncp */
#define PHYS_NCP_LINK_ESTAB_INVALID_VER  12 /* Remote NCP is V1.0 !!*/
#define PHYS_NCP_LINK_END 13            /* remote NCP is terminating */
#define PHYS_SERCONFIG_FAILED   14      /* serial port not there */

#define MAX_DVR_NAME    10   /* Max device driver name size (incl zero term) */
#define MAX_PHONE_NO    40   /* Max phone number length */
#define MAX_MODEM_CMD   40   /* Max extra modem config */

/* Control functions to perform */
#define NCLINK_CTRL_RETRY   0
#define NCLINK_CTRL_EXIT    1
#define NCLINK_CTRL_NEWNCP_OK   2
#define NCLINK_CTRL_NEW_CONFIG  3

typedef struct
    {
    P_SRCHAR sch;
    P_MDMCHR mch;
    UWORD errcorrect;           /* what sort of error correction modem using */
    UWORD connectbaud;          /* baud rate at which connected */
    UBYTE serdvr[MAX_DVR_NAME];
    UBYTE mdmdvr[MAX_DVR_NAME];
    UBYTE masdvr[MAX_DVR_NAME];
    UBYTE lnkdvr[MAX_DVR_NAME];
    UBYTE phoneno[MAX_PHONE_NO];
    UBYTE mdmconf[MAX_MODEM_CMD];
    } DVRS;

typedef struct
    {
    UWORD vers;      /* Remote NCP sofware version */
    ULONG id;           /* Remote NCP id */
    } REM_NCP;

typedef union
    {
    REM_NCP remncp;     /* Remote NCP info */
    DVRS dvrs;          /* Driver names, phone number */
    } PHY_INFO;

typedef struct          /* Physical layer status information */
    {
    UWORD cmdtype;      /* Info type */
    WORD errno;         /* Error number if applicable to type */
    PHY_INFO p;         /* Physical layer info */
    } NCLINK_INFO;

typedef struct          /* Network sense data struct */
    {
    UWORD chanused;     /* True if channel being used else False */
    ULONG xmitK;        /* number K bytes transmitted */
    ULONG recvK;        /* number K bytes received */
    UBYTE procname[E_MAX_NAME+2]; /* Process name that owns channel */
    } NCLINK_SREC;

