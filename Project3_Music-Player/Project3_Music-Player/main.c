/*
 * Project3_Music-Player.c
 *
 * Created: 4/27/2016 5:20:06 PM
 * Author : Tej Vuligonda
 */ 

#include <avr/io.h>
#include "avr.h"
#include "lcd.h"
#include "keypad.h"
#include "music.h"
#include <math.h>

static double const tenToNegativeSix = pow(10.0,-6.0);


int main(void)
{
   /* Replace with your application code */
   
   DDRB = 0x01 << 3;
   
   ini_lcd();
   pos_lcd(0,0);
   puts_lcd2("1:Hot Cross Buns");
   pos_lcd(1,0);
   puts_lcd2("2:ABC's");
   //LCD CAN HAVE 16 CHARACTERS
   
	for (;;) {
		unsigned char key = get_key();
		if (key == 1) {
			playHotCrossBuns();
		}
		if (key == 2) {
			playABC();
		}
	}

   
   
   
   
   


   

   return 0;

}

