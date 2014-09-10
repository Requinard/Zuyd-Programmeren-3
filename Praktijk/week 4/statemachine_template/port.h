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

// LED connections
sbit LED0_pin = P0^0;
sbit LED1_pin = P0^1;
sbit LED2_pin = P0^2;
sbit LED3_pin = P0^3;
sbit LED4_pin = P0^4;
sbit LED5_pin = P0^5;
sbit LED6_pin = P0^6;
sbit LED7_pin = P0^7;

// Switches
sbit SW1  = P1^6;
sbit SW2  = P1^7; 
#define SW1_PRESSED() !SW1
#define SW2_PRESSED() !SW2

// PCB: MotorControl_v0.1
sbit LEFT = P2^6;
sbit RIGHT = P2^5;

#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/