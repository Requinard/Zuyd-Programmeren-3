#ifndef _CTIMER_H
#define _CTIMER_H

/* ----------------------- Platform includes --------------------------------*/
#include "ADuC847.h"

/* ----------------------- Defines ------------------------------------------*/
#define SCLK          ( 12582912UL ) /* system clock: PLL output */
#define ACLK          ( 32768UL )    /* analog clock: PLL input  */

typedef char    	   BOOL;
typedef unsigned char  UCHAR;
typedef char    	   CHAR;
typedef unsigned short USHORT;
typedef short   	   SHORT;
typedef unsigned long  ULONG;
typedef long           LONG;

#ifndef TRUE
#define TRUE            1
#endif

#ifndef FALSE
#define FALSE           0
#endif

BOOL initTimer0( USHORT );
void enableTimer0( void );
void disableTimer0( void );
extern void (T0_overflow)(void);

#endif
