#include "main.h"
#include "port.h"
#include "LED_flash.h"

// ------ Private variable definitions -----------------------------

static bit LED5_state_G;

/*------------------------------------------------------------------*-

  LED5_Flash_Init()

  - See below.

-*------------------------------------------------------------------*/
void LED5_Flash_Init(void)
{
   LED5_state_G = 0;
}

/*------------------------------------------------------------------*-

  LED_Flash_Update()

  Flashes an LED (or pulses a buzzer, etc) on a specified port pin.

  Must schedule at twice the required flash rate: thus, for 1 Hz
  flash (on for 0.5 seconds, off for 0.5 seconds) must schedule
  at 2 Hz.

-*------------------------------------------------------------------*/
void LED5_Flash_Update(void)
{
   // Change the LED from OFF to ON (or vice versa)
   if (LED5_state_G == 1) {
      LED5_state_G = 0;
      LED5_pin = 0;
   }
   else {
      LED5_state_G = 1;
      LED5_pin = 1;
   }
}

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
