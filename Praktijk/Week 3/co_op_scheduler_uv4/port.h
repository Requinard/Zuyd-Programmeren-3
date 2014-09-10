#ifndef _PORT_H
#define _PORT_H

// Comment this line out if error reporting is NOT required
#define SCH_REPORT_ERRORS

#ifdef SCH_REPORT_ERRORS
// The port on which error codes will be displayed
// ONLY USED IF ERRORS ARE REPORTED
#define Error_port P2

#endif

// ------ LED_Flash.c -----------------------------------------------

// Connect LED from +5V (etc) to this pin, via appropriate resistor
sbit LED5_pin = P0^5;

#endif
/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/