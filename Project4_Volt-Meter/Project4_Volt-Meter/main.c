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
#include <limits.h>

char line1[17];
char line2[17];

int main(void)
{
	ini_lcd();

	init_registers();
	
	// set_lcd_lines("1:Begin Sampling", "2:Restart");
	unsigned int average = 0;
	unsigned int count = 0;
	unsigned int max = 0;
	unsigned int min = INT_MAX;
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
				
				struct voltages values = calc_adc(average, count, max, min);
				
				
				sprintf(line1,"%d",values.inst_voltage);
				
				puts_lcd2(line1);
				

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



