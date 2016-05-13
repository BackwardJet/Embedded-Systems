/*
 * Project4_Volt-Meter.c
 *
 * Created: 5/11/2016 5:16:28 PM
 * Author : Tej Vuligonda
 */ 

#include "avr.h"
#include "lcd.h"



int main(void)
{
	ini_lcd();
	puts_lcd2("PROJECT 4");
	
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,6);
	
	// ADMUX = (1 << 6) | (1 << 1) | (1 << 0);
	ADMUX = (1 << REFS0) | (1 << MUX1) | (1 << MUX0);
	
}

