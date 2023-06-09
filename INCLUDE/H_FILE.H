/*
HEADER - H_FILE.H
*/

#define H_FILE_H

#define H_FILE_ALLOW_DIRS       0x02
#define H_FILE_JUST_DIRS        0x04
#define H_FILE_FORCE_NXIST      0x08
#define H_FILE_NO_AUTOQUERY     0x10
#define H_FILE_ACCEPT_NULL      0x20
#define H_FILE_SET_DEFEXT       0x40
#define H_FILE_CAN_WILDCARD     0x80

#define H_FILE_STANDARD_INIT    0x01
#define H_FILE_RESTRICT_LIST    H_FILE_FORCE_NXIST
#define H_FILE_CAN_TAG          H_FILE_NO_AUTOQUERY

#define H_FILE_HWIF_MASK        0xfe
#define H_FILE_PICK_SELECTOR    0
#define H_FILE_NEW_EDITOR       0x01

#define H_FILE_IS_DIR           0x01
#define H_FILE_AT_ROOT          0x02
#define H_FILE_IS_ROOT          0x03
