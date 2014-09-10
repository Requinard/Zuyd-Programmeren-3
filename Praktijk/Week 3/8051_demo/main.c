#include "ADuC847.h"
#include "init.h"
#include "ctimer.h"

int cnt = 0;

void main()
{
    init();               // microcontroller initialisation
    initTimer0 ( 2000 ); // One-Task scheduler; a TICK every 40000*50 micro-seconds
    enableTimer0();       // activate timer
    for( ;; ) {           // superloop

    }
}

void T0_overflow(void)
{
	if(P0 == 0)
		P0 = 1;
	else if ( P0 < 128)
		P0 <<= 1;
	else
		P0 = 1;
}

