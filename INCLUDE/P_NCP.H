/*	HEADER - P_NCP.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_NCP_H
#include <stdepoc.h>
#define NCLINK_VERSION_NUMBER 3
#define NCLINK_MINOR_VERNO 1
typedef struct
{
unsigned char *pcb;       /* Handle to call */ 
int handler;      /* Handler handler */ 
unsigned char *(*Install)();  /* Install server */ 
void (*Remove)();    /* Remove the server */ 
int (*WaitHandler)();  /* Wait handler function to call */ 
unsigned char name[16];     /* name of the server */ 
} P_NCP;
/* Informational data obtained by supervisory reads */
#define PHYS_LINK_FAILED    0    /* Link layer has failed*/ 
#define PHYS_CONNECT_FAILED   1    /* Waiting for connection failed */ 
#define PHYS_CHARS_FAILED    2    /* Setting serial characteristics failed */ 
#define PHYS_INIT_FAILED    3    /* Initialization of modem failed */ 
#define PHYS_DIAL_FAILED    4    /* Dialling phone number failed */ 
#define PHYS_MDMCONFIG_FAILED  5    /* additional modem config failed */ 
#define PHYS_PHYS_LINK_ESTABLISHED 6  /* A physical link established */ 
#define PHYS_WAITING_FOR_CALL  7    /* Physical layer waiting for call */ 
#define PHYS_DIALLING_NUMBER  8    /* Physical layer dialling */ 
#define PHYS_CONFIGURING_MODEM 9    /* configuring modem */ 
#define PHYS_NCP_LINK_ESTAB_OK 10    /* Ncp link established OK */ 
#define PHYS_NCP_LINK_ESTAB_NEW_NCP 11 /* Talking to different Ncp */ 
#define PHYS_NCP_LINK_ESTAB_INVALID_VER 12 /* Remote NCP is V1.0 !!*/ 
#define PHYS_NCP_LINK_END 13      /* remote NCP is terminating */ 
#define PHYS_SERCONFIG_FAILED  14   /* serial port not there */ 
/* type of message to add to the queue */
#define NCONT_MSG_SEND 0  /* controller */ 
#define NUSER_MSG_SEND 1  /* users */ 
#define NEXPEDIATED_MSG_SEND 2 /* expediated */ 
/***************************************************************************/
/* NUCB flags defines */
#define NUFLAG_WRITE_HELD      0x01
#define NUFLAG_WRITE_OUTSTANDING  0x02
#define NUFLAG_CONNECT_REQUEST   0x08
#define NUFLAG_DISCONNECTED     0x10
#define NUFLAG_ALLOCATED      0x20
#define NUFLAG_CHANNEL_CLOSED    0x40
#define NUFLAG_DISCONNECT_REQUEST  0x80
#define NUFLAG_TEMPDISC       0x100
#define NUFLAG_NO_CONNECTION    (NUFLAG_TEMPDISC|NUFLAG_DISCONNECTED)
#define NC_VERSION_NUMBER  2    /* were version 2 */ 
#define NC_MAX_USERCB    8    /* Max number of connected users */ 
#define NC_MSG_SIZE     8    /* Max inter controller msg size */ 
typedef struct nudata      /* Network user data control block */ 
{
struct nudata *pnudata;   /* next control blk in list */ 
unsigned short int reclen;        /* amount in buffer */ 
unsigned char recbuf[1];      /* expands as required (for C offset) */ 
} NUDATA;
typedef struct         /* Network User control block */ 
{
P_ICB icb;         /* I/O control block */ 
unsigned short int flags;        /* controlling flags */ 
P_RQPKT read;        /* read request block */ 
P_RQPKT write;       /* write request block */ 
P_RQPKT super;       /* supervisory read request blk */ 
P_NCP *pncp;        /* open channel control blk ptr */ 
unsigned char localchanid;     /* local channel id number */ 
unsigned char remotechanid;     /* remote channel id number */ 
unsigned char *pncb;        /* Network handle */ 
unsigned char *handler;       /* Network client wait handler handle */ 
NUDATA *pnudata;      /* Network users queued data */ 
unsigned short int nclen;        /* amount in the Network Controller msg buffer */ 
unsigned char ncbuf[NC_MSG_SIZE];  /* message buffer */ 
unsigned short int recvbytes;      /* Number of bytes received (>1K) */ 
unsigned short int xmitbytes;      /* Number of bytes xmitted (>1K) */ 
unsigned long int recvK;        /* Number of K received */ 
unsigned long int xmitK;        /* Number of K transmitted */ 
} NUCB;
/*************************************************************************/
/* Inter controller message types */
#define NCON_MSG_DATA_XOFF     1
#define NCON_MSG_DATA_XON      2
#define NCON_MSG_CONNECT_TO_SERVER 3
#define NCON_MSG_CONNECT_RESPONSE  4
#define NCON_MSG_CHANNEL_CLOSED   5
#define NCON_MSG_NCP_INFO      6    /* MUST BE 6 for older versions*/ 
#define NCON_MSG_CHANNEL_DISCONNECT 7
#define NCON_MSG_NCP_END      8
/* Inter Network user message types */
#define NU_MSG_WRITECOMPLETE    1
#define NU_MSG_WRITEPARTIAL     2
#define NC_LINK_ACTIVE   0x01
#define NC_READ_QUEUED   0x02
#define NC_WRITE_QUEUED   0x04
#define NC_TERMINATING   0x08
#define NC_OWNER_CLOSE_REQUEST 0x10
#define CONNECT_STATE_0 0
#define CONNECT_STATE_1 1
#define CONNECT_STATE_2 2
typedef struct
{
unsigned short int flags;      /* Controlling flags */ 
short int ctrlmsgqueue;   /* Network users have controller messages queued */ 
short int ctrllastxmit;   /* Network users last transmitted a ctrl msg */ 
short int usermsgqueue;   /* Network users have queued write requests */ 
short int userlastxmit;   /* Network users last transmitted a user msg */ 
unsigned short int maxfrmsize;    /* maximum frame we can transmit/receive */ 
short int wstat;       /* Write completion status */ 
short int rstat;       /* Read completion status */ 
unsigned short int wlen;       /* Write length */ 
unsigned short int rlen;       /* Read length */ 
unsigned char *handler;     /* Network controller wait handler handle */ 
unsigned char *plcb;      /* link layer that were using */ 
unsigned short int connected;    /* connected state */ 
unsigned short int remotencpver;   /* the remote NCP version number */ 
unsigned long int startdate;    /* NCP start up date (logon id) */ 
unsigned long int remotestartdate; /* the remote NCP logon id */ 
unsigned short int expediatedlen;  /* amount in expediated buf to transmit */ 
unsigned char expediatedbuf[NC_MSG_SIZE];
NUCB *lastnucb;     /* last network user to do a write */ 
unsigned char rbuf[P_MAXILEN];  /* read buffer */ 
unsigned char wbuf[P_MAXILEN];  /* write buffer */ 
NUCB usertable[NC_MAX_USERCB];
} NCB;
