/*
MUX.H Defines for the Psion IRDA IRMUX implementation
Written by Jason J Robinson 1st November 1996
PSION PLC 1995/96
*/

/* Irmux user port defines */
/* User can choose ports in range 1-126 */
/* Port zero is always the IAS */
/* Port number 128 is reserved for ports awaiting connection */

#define MaxPortNumber      126
#define MUX_NOTCONNECTED   128

/* Irmux state machine states */

#define LM_SNIFF           0
#define LM_DISCOVER        1
#define LM_RESOLVEADDR     2
#define LM_READY           3
#define LM_READYPEND       4
#define LM_EXCLUSIVEPEND   5
#define LM_EXCLUSIVE       6
#define LM_ROLEEXCHANGE    7

/* Client services */
/* IPC call message numbers */

#define LM_Logon                    1
#define LM_Logoff                   2
#define LM_EmergencyLogoff          3

/* Irmux connectionless services */
/* IPC call message numbers */

#define LM_CLReadRequest            4
#define LM_CLWriteRequest           5
#define LM_DiscoverDevicesRequest   6
#define LM_SniffRequest             7
#define LM_WaitForConnection        8
#define LM_ConnectRequest           9
#define LM_RegisterPort             10
#define LM_UnRegisterPort           11

/* Irmux connection based services */
/* IPC call message numbers */

#define LM_DisconnectRequest        20
#define LM_StatusRequest            21
#define LM_AccessModeRequest        22
#define LM_IdleRequest              23
#define LM_ReadRequest              24
#define LM_WriteRequest             25
#define LM_UReadRequest             26
#define LM_UWriteRequest            27
#define LM_SetHandshakingLevel      28

/* IAS services */
/* Not implemented in current stack versions */

#define LM_GetValueByClass          32
#define LM_GetInfoBaseDetails       33
#define LM_GetObjects               34
#define LM_GetValue                 35
#define LM_GetObjectInfo            36
#define LM_GetAttributeNames        37

/* IPC call message numbers */
/* Constants */

#define FirstConnectionBasedFunction LM_DisconnectRequest
#define MaxMessageNumber            38

/* IPC call message parameters and modes */
/* Exclusive mode */

#define LM_ExclusiveMode         1
#define LM_MultiplexMode         0

/* Connection mode */

#define MUX_PRIMARY              1
#define MUX_SECONDARY            2

/* Mux level frame fromats */
/* Control frame codes */

#define MUX_CONTROL_FRAME         0x80
#define MUX_DISCONNECT_OPCODE     0x02
#define MUX_CONNECT_OPCODE        0x01
#define MUX_CONNECTCONFIRM_OPCODE 0x81
#define MUX_ACCESS_OPCODE         0x03
#define MUX_ACCESSCONFIRM_OPCODE  0x83

#define MUX_MODE_NOT_EXCLUSIVE   0x00
#define MUX_MODE_EXCLUSIVE       0x01

#define CompleteRequest    p_mfree

/* Function returns */

#define OKAY                      0
#define MUX_DISCOVERY_COMPLETE    0
#define MUX_CACHE_USED            1

/* Function error returns */

#define E_MUX_USERDISCONNECT     -1
#define E_MUX_LOGOFFDISCONNECT   -2
#define E_MUX_REMOTEDISCONNECT   -3
#define E_MUX_TIMEOUTDISCONNECT  -4
#define E_MUX_EXCLUSIVE          -5
#define E_MUX_BUSY               -6
#define E_MUX_LAP                -7
#define E_MUX_INUSE              -8
#define E_MUX_NOCONNECTION       -9
#define E_MUX_TIMEOUT            -10
#define E_MUX_ABORT              -11
#define E_MUX_LOGON              -12
#define E_GEN_BATIRDA            -26

/* Irmux disconnect reasons */
/* Errors returned in disconnect frames */

#define MUX_DISCONNECT_USER                  0x01
#define MUX_DISCONNECT_REASON_VAGUE          0x05
#define MUX_DISCONNECT_NOT_CONNECTED_REASON  0x06
#define MUX_DISCONNECT_NO_CLIENT             0x08

#define AccessModeTimeout     2000
#define ConnectFrameTimeout   2000

#define DisconnectRequestLength     4
#define ConnectRequestLength        64
#define MuxConnectInfoLength        60
#define ExclusiveRequestLength      5
#define EndExclusiveRequestLength   5
#define ConnectConfirmLength        64
#define ExclusiveReplyLength        5

#define MuxMaxResetCountMinusOne    4

/* IRMUX panic numbers */

#define MUX_PANIC_NOTDISCOVERY      180
#define PANIC_MUX_RESOLVE           181
#define PANIC_MUX_STATUSINDICATION  182
#define MUX_PANIC_NOFUNCTION        184
#define PANIC_MUX_CONNECTCONFIRM    185
#define PANIC_MUX_DISCONNECTINDICATION 186
#define PANIC_MUX_DATAINDICATION    187
#define PANIC_MUX_RESETCONFIRM      188
#define PANIC_MUX_RESETINDICATION   190
#define MUX_PANIC_LOSTLAPCONNECTION 191
#define MUX_PANIC_MEMORY            196

#define IASLast                     0x80
#define IASAck                      0x40
#define IASGetValueByClass          0x04
