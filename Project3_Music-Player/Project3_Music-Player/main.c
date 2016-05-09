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

//No need for this anymore
//static double const tenToNegativeSix = pow(10.0,-6.0);

struct note {
	unsigned char freq;
	unsigned char duration;
};



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

void play_note(char freq, char dur)
{
	for(int i = 0; i < (dur/2*2); i++)
	{
		SET_BIT(PORTB,3);
		wait_avr(freq);
		CLR_BIT(PORTB,3);
		wait_avr(freq);
	}
	
}

void play_music(struct note *song[],int n)
{
	
	for (int i = 0;  i < n; i++)
	{
		play_note(song[i]->freq, song[i]->duration);
	}
}




int main(void)
{
    /* Replace with your application code */
	
	DDRB = 0x01 << 3;
	
	ini_lcd();
	puts_lcd2("PROJECT 3");
	
	
	struct note mySong[] = {{127.5510204,1},{63.7755102,1},{190.8396947,1},{63.7755102,1},
							{113.6363636,3},{127.5510204,3},{170.0680272,1},{127.5510204,1}
								};
	int n = 8;	
	
	play_music(mySong, n);
	
	return 0;
	
}