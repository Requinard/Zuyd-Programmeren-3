#include "main.h"

#include "sch51_init.h"
/* ............................................................... */
/* ............................................................... */

//LED FUNCS
void led0(void)
{
	P0 = P0 ^ 1;
}

void led1(void)
{
	P0 = P0 ^2;
}

void led2(void)
{
	P0 = P0 ^4;
}

void led3(void)
{
	P0 = P0 ^8;
}

void led4(void)
{
	P0 = P0 ^16;
}

void led5(void)
{
	P0 = P0 ^32;
}

void led6(void)
{
	P0 = P0 ^64;
}
void led7(void)
{
	P0 = P0 ^128;
}
//EINDE LEDS

void main(void)
{
   // setup microcontroller
   PLLCON = 0x00;
   P0 = 0x00;
   
   // Set up the scheduler
   SCH_Init_T2();

   // Add the 'Flash LED' task (on for ~1000 ms, off for ~1000 ms)
   // - timings are in ticks (~1 ms tick interval)
   // (Max interval / delay is 65535 ticks)
   SCH_Add_Task(led0, 0, 100);
   SCH_Add_Task(led1, 5, 200);
   SCH_Add_Task(led2, 10, 400);
   SCH_Add_Task(led3, 15, 800);
   SCH_Add_Task(led4, 20, 1000);
   SCH_Add_Task(led5, 25, 2000);
   SCH_Add_Task(led6, 30, 5000);
   SCH_Add_Task(led7, 35, 10000);

   // Start the scheduler
   SCH_Start();

   while(1) {
      SCH_Dispatch_Tasks();
   }
}


/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
