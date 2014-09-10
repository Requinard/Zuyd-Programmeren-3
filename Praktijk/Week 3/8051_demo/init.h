#ifndef _INIT_H
#define _INIT_H

#include "ADuC847.h"

// MotorControl_v0.1
sbit FORWARD = P2^6;
sbit REVERSE = P2^5;

// LEDS
sbit LED1 = P0^0;
sbit LED2 = P0^1;

// switches
sbit SW1  = P1^6;
sbit SW2  = P1^7;
#define SW1_PRESSED() !SW1
#define SW2_PRESSED() !SW2

// functie-prototypes
void init (void);

#endif