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

char buf[17];

int main(void)
{
	ini_lcd();

	init_registers();
	
	// set_lcd_lines("1:Begin Sampling", "2:Restart");
	
	for (;;) {
		unsigned char key = get_key();
		set_lcd_lines("1:Begin Sampling", "2:Restart");
		if (key == 1) {
			// start sampling
			clr_lcd();
			puts_lcd2("key 1 pressed");
			while (1) {
				unsigned char key_again = get_key();
				if (key_again == 2) {
					// reset
					clr_lcd();
					puts_lcd2("key2 pressed");
					break;
				}
				wait_avr(500);
				clr_lcd();
				
				unsigned int result = calc_adc();
				
				sprintf(buf,"%d",result);
				
				puts_lcd2(buf);
				

			}
		}
		/*
		if (key == 2) {
			// reset
			clr_lcd();
			puts_lcd2("key 2 pressed");
		}
		*/
	}
	
}



