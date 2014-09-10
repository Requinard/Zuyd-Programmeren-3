#include "main.h"
#include "sch51_init.h"
#include "my_statemachine.h"

/* ............................................................... */
/* ............................................................... */

void main(void)
{  
   // setup microcontroller
   PLLCON = 0x00;
   P0 = 0x00;
   P1 &= ~(1<<6);
   P1 &= ~(1<<7);

   // Set up the scheduler
   SCH_Init_T2();

   // init tasks
   init_statemachine();

   // - timings are in ticks (~1 ms tick interval)
   SCH_Add_Task(statemachine, 0, 10);
   SCH_Add_Task(switchStateMachine, 5, 20);

   // Start the scheduler
   SCH_Start();				

   while(1) {
      SCH_Dispatch_Tasks();
   }
}

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
