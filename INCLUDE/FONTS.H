/*
  File: FONTS.H
  Copyright (C) Psion PLC 1993
  Started by : DavidW
  Started in:  April 1993 (derived from earlier contents of Hwim.cat)

  The fonts listed in sxwim.rom (and in egclient.par), in order:

    S3.FON          6000,1,2,3      (SYS$NORM,SYS$BOLD,SYS$DIGT,*)
    SA13S.FON       6004,5,6,7      (SA13SN,SA13SNM,SA13SB,*)
    SA13R.FON       6008,9,a        (SA13RN,SA13RB,*)
    SA16RN.FON      600b
    SA16SN.FON      600c
    SA11S.FON       600d,e,f        (SA11SN,SA11SB,*)
    SA11R.FON       6010,11,12      (SA11RN,SA11RB,*)
    SA08S.FON       6013,14,15      (SA08SN,SA08SB,*)
    SA08RND4.FON    6016
    SA08RBD4.FON    6017
    SA37SND.FON     6018
    SA08SN5.FON     6019
    SA07RBA.FON     601a
    SA05RND.FON     601b
    AGN8SYM.FON     601c
    AGN13SYM.FON    601d
    SA08RNM8.FON    601e
    SA06RNM6.FON    601f
    SPR05RN4.FON    6020
    SA15SND.FON     6021
    SA11SYM.FON     6022
    WORLD.FON       6023

  The numerical contents of sys$wsrv.fsu (defines the 4000 numbered fonts):

    0,1,2,              Series3 fonts
    1e,                 8x8 mono
    3,12,a,b,           4 Roman fonts: 8/11/13/16
    15,f,7,c,           4 Swiss fonts: 8/11/13/16
    1f                  6x6 mono

  "Server fonts" in egclient.par (and in xhhenv.ini) (all are 6000 numbers):
    7           S3b system font
    4           S3b notifer/alert message font ("internal font")
    13 (d)      status window diamond bar text font
    13 (d)      status window diamond bar symbol font
    24 (18)     "medium 2" digital clock font
    13 (d)      "medium 2" date font
    4           button text in notifiers and alerts
    33 (21)     small digital clock font
*/

/*
Series 3 fonts
*/
#define FONT_ID_S3              WS_FONT_BASE
#define FONT_ID_S3BOLD          (WS_FONT_BASE+0x1)
#define FONT_ID_S3DIGITS        (WS_FONT_BASE+0x2)

/*
Series 3B supported fonts
*/
#define FONT_ID_MONO_8x8        (WS_FONT_BASE+0x3)
#define FONT_ID_ROMAN_8         (WS_FONT_BASE+0x4)
#define FONT_ID_ROMAN_11        (WS_FONT_BASE+0x5)
#define FONT_ID_ROMAN_13        (WS_FONT_BASE+0x6)
#define FONT_ID_ROMAN_16        (WS_FONT_BASE+0x7)
#define FONT_ID_SWISS_8         (WS_FONT_BASE+0x8)
#define FONT_ID_SWISS_11        (WS_FONT_BASE+0x9)
#define FONT_ID_SWISS_13        (WS_FONT_BASE+0xa)
#define FONT_ID_SWISS_16        (WS_FONT_BASE+0xb)
#define FONT_ID_MONO_6x6        (WS_FONT_BASE+0xc)

/*
Series 3B specialised fonts, not necessarily supported on future machines
*/
#define FONT_ID_DIGITS_8x4      (WS_FONT_BASE2+0x16)
#define FONT_ID_DIGITS_8x4B     (WS_FONT_BASE2+0x17)
#define FONT_ID_CLOCK_37        (WS_FONT_BASE2+0x18)
#define FONT_ID_SWISS_8_THIN    (WS_FONT_BASE2+0x19)
#define FONT_ID_ALPHA_UC_7B     (WS_FONT_BASE2+0x1a)
#define FONT_ID_DIGITS_5x4      (WS_FONT_BASE2+0x1b)
#define FONT_ID_AGN_SYM_8       (WS_FONT_BASE2+0x1c)
#define FONT_ID_AGN_SYM_13      (WS_FONT_BASE2+0x1d)
#define FONT_ID_SPR_5x4         (WS_FONT_BASE2+0x20)
#define FONT_ID_CLOCK_15        (WS_FONT_BASE2+0x21)

/*
Vine and s3d fonts
*/
#define FONT_ID_SA_11_SYM       (WS_FONT_BASE2+0x22)
#define FONT_ID_WORLD           (WS_FONT_BASE2+0x23)

/*
Font ids that are component parts of configured groups
*/
#define FONT_ID_13_S            (WS_FONT_BASE2+0x4)
#define FONT_ID_13M_S           (WS_FONT_BASE2+0x5)
#define FONT_ID_13B_S           (WS_FONT_BASE2+0x6)
#define FONT_ID_13_R            (WS_FONT_BASE2+0x8)
#define FONT_ID_13B_R           (WS_FONT_BASE2+0x9)
#define FONT_ID_11_S            (WS_FONT_BASE2+0xd)
#define FONT_ID_11B_S           (WS_FONT_BASE2+0xe)
#define FONT_ID_11_R            (WS_FONT_BASE2+0x10)
#define FONT_ID_11B_R           (WS_FONT_BASE2+0x11)
#define FONT_ID_8_S             (WS_FONT_BASE2+0x13)
#define FONT_ID_8B_S            (WS_FONT_BASE2+0x14)
