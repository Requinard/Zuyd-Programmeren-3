#include "LEDS.h"

void led0(void)
{
	P0 = P0 ^ 1;
}

void led1(void);
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