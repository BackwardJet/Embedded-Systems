/*
 * Project4_Volt-Meter.c
 *
 * Created: 5/11/2016 5:16:28 PM
 * Author : Tej Vuligonda
 */ 

#include "avr.h"
#include "lcd.h"
#include "keypad.h"
#include "voltmeter.h"
#include <stdio.h>


int main(void)
{
	ini_lcd();

	init_registers();
	
	set_lcd_lines("1:Begin Sampling", "2:Restart");
	
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



