/*
 * Project4_Volt-Meter.c
 *
 * Created: 5/11/2016 5:16:28 PM
 * Author : Tej Vuligonda
 */ 

#include "avr.h"
#include "lcd.h"
#include "keypad.h"



int main(void)
{
	ini_lcd();
	// puts_lcd2("PROJECT 4");
	
	SET_BIT(ADMUX,1);
	SET_BIT(ADMUX,6);
	
	// ADMUX = (1 << 6) | (1 << 1) | (1 << 0);
	ADMUX = (1 << REFS0) | (1 << MUX1) | (1 << MUX0);
	
	ADCSRA = (1 << ADEN) | (1 << ADSC);
	
	
	
	pos_lcd(0,0);
	puts_lcd2("1:Begin Sampling");
	pos_lcd(1,0);
	puts_lcd2("2:Restart");
	for (;;) {
		unsigned char key = get_key();
		if (key == 1) {
			// start sampling
			clr_lcd();
			puts_lcd2("key 1 pressed");
			while (1) {
				wait_avr(500);
			}
		}
		if (key == 2) {
			// reset
			clr_lcd();
			puts_lcd2("key 2 pressed");
		}
	}
	
}

