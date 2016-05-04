/*
 * Project3_Music-Player.c
 *
 * Created: 4/27/2016 5:20:06 PM
 * Author : Tej Vuligonda
 */ 

#include <avr/io.h>
#include "avr.h"
#include "lcd.h"
#include <math.h>

static double const tenToNegativeSix = pow(10.0,-6.0);

unsigned char pressed(int r, int c) {
	// PUT ALL ROW AND COL PINS TO NO-CONNECT (DDR = 0, PORT = 0)
	// PUT THE r-th ROW TO '0'
	// PUT THE c-th COL to 'Z'
	// GET THE c-th COL (return 0 or 1, depending of PIN's status)
	DDRC = 0;
	PORTC = 0;

	SET_BIT(PORTC,r);
	SET_BIT(DDRC,c+4);
	CLR_BIT(PORTC,c+4);

	if(!GET_BIT(PINC,r))
	return 1;

	return 0;
}

unsigned char get_key() {
	unsigned char r,c;
	for (r = 0; r < 4; ++r) {
		for (c = 0; c < 4; ++c) {
			if (pressed(r,c)) {
				return (r*4) + c + 1;
			}
		}
	}
	return 0;
}





int main(void)
{
    /* Replace with your application code */
	
	DDRB = 0x01 << 3;
	
	ini_lcd();
	puts_lcd2("PROJECT 3");
	
	/*for (int k = 0; k < 2; k++) {
	
		for (int i = 0; i < 100; i++) { // G
			unsigned char key = get_key();
		
			SET_BIT(PORTB,3);
			wait_avr(392.00);
			CLR_BIT(PORTB,3);
			wait_avr(392.00);
		
			if (key == 13) { // keypad: *
				break;
			}
		
		}
		*/
	
		unsigned short msec = (1/440*tenToNegativeSix);
		
	
		for (;;) { // A
			unsigned char key = get_key();
				
			SET_BIT(PORTB,3);
			wait_avr(msec/2);
			CLR_BIT(PORTB,3);
			wait_avr(msec/2);
		
			if (key == 13) { // keypad: *
				break;
			}
		
		}
	/*
		for (int i = 0; i < 200; i++) { // B
			unsigned char key = get_key();
		
			SET_BIT(PORTB,3);
			wait_avr(493.88);
			CLR_BIT(PORTB,3);
			wait_avr(493.88);
		
			if (key == 13) { // keypad: *
				break;
			}
		
		}
		
	}
	*/
	
	
	
	
	
}

