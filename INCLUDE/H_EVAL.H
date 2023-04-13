/*      HEADER - H_EVAL.H
Epoc/Os structures and constants.
Copyright (c) Psion PLC 1991.

 VER    DATE    BY  DESCRIPTION
----- -------- ---- -----------
1.00F 12/03/91 PST  Final release
*/

#define EVAL_DEFAULT_PLACES 2
#define EVAL_DEFAULT_FMT_TYPE   P_DTOB_FIXED
#define CALC_MAX_PLACES	12
#define CALC_DEFAULT_PLACES	  CALC_MAX_PLACES
#define CALC_DEFAULT_FMT_TYPE  P_DTOB_GENERAL
#define MAX_MEMORIES 10

typedef struct
    {
    UBYTE evalFormat; /* Dtob format code for all except calc */
    UBYTE evalDPlaces; /* Decimal places for all except calc */
    UBYTE calcFormat; /* Dtob format code */
    UBYTE calcDPlaces; /* Decimal places, if relevant */
    DOUBLE values[MAX_MEMORIES];
    } MEM_VALUES;

typedef struct
    {
    UBYTE nameLbc;
    UBYTE name[3];
    UBYTE valueLbc;
    MEM_VALUES value;
    } MEM_ENV; 

typedef struct
    {
    UBYTE evalDegrees;
    UBYTE calcDegrees;
    MEM_VALUES memVal;
    } EXTENDED_MEM_VALUES;
