/*	HEADER - P_GEN.H
Copyright (C) Psion PLC 1991-92
 VER    DATE   BY  DESCRIPTION
===== ======== === ===========
1.00F 26/04/90 NSM First relase
1.10F 07/07/92 NSM Second release
*/
#define P_GEN_H
#include <stdepoc.h>
/* general errors */
#define NoErr 0   /* no error !! */ 
#define FailErr (-1) /* Failure */ 
#define ArgumentErr (-2) /* Invalid arguments */ 
#define OsErr (-3) /* Operating system error */ 
#define NotSupportedErr (-4) /* Not supported function */ 
#define UnderflowErr (-5) /* Underflow */ 
#define OverflowErr (-6) /* Overflow */ 
#define E_GEN_FAIL FailErr
#define E_GEN_ARG ArgumentErr
#define E_GEN_OS OsErr
#define E_GEN_NSUP NotSupportedErr
#define E_GEN_UNDER UnderflowErr
#define E_GEN_OVER OverflowErr
#define RangeErr (-7) /* Argument range */ 
#define DivideByZeroErr (-8) /* Divide by zero */ 
#define InUseErr (-9) /* Resource in use */ 
#define NoMemoryErr (-10) /* No memory left */ 
#define NoSegmentsErr (-11) /* No segments left */ 
#define NoSemaphoreErr (-12) /* No semaphores left */ 
#define NoProcessErr (-13) /* No processes left */ 
#define AlreadyOpenErr (-14) /* Resource already open */ 
#define NotOpenErr (-15) /* Resource not open */ 
#define ImageErr (-16) /* Invalid image file */ 
#define NoReceiverErr (-17) /* No message receiver */ 
#define NoDevicesErr (-18) /* No devices left */ 
#define NoFileSystemErr (-19) /* No file system left */ 
#define FailedToStartErr (-20) /* Failed to start application */ 
#define FontNotLoadedErr (-21)
#define TooWideErr (-22)
#define TooManyItemsErr	(-23)
#define BatLowSoundErr (-24)
#define BatLowFlashErr (-25)
#define E_GEN_RANGE RangeErr
#define E_GEN_DIVIDE DivideByZeroErr
#define E_GEN_INUSE InUseErr
#define E_GEN_NOMEMORY NoMemoryErr
#define E_GEN_NOSEGMENTS NoSegmentsErr
#define E_GEN_NOSEM NoSemaphoreErr
#define E_GEN_NOPROC NoProcessErr
#define E_GEN_OPEN AlreadyOpenErr
#define E_GEN_NOTOPEN NotOpenErr
#define E_GEN_IMAGE ImageErr
#define E_GEN_RECEIVER NoReceiverErr
#define E_GEN_DEVICE NoDevicesErr
#define E_GEN_FSYS NoFileSystemErr
#define E_GEN_START FailedToStartErr
#define E_GEN_NOFONT FontNotLoadedErr
#define E_GEN_TOOWIDE TooWideErr
#define E_GEN_TOOMANY TooManyItemsErr
#define E_GEN_BATSOUND BatLowSoundErr
#define E_GEN_BATFLASH BatLowFlashErr
#define E_KILLEXIT 0 /* Died by being killed */ 
#define E_PANICEXIT 1 /* Died by a panic */ 
