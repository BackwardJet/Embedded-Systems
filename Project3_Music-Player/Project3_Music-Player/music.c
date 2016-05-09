/*
 * CFile1.c
 *
 * Created: 5/3/2016 7:32:12 PM
 *  Author: Tej Vuligonda
 */ 
#include "music.h"
#include "avr.h"


void play_note(int freq, int dur)
{
	for(int i = 0; i < (dur); i++)
	{
		SET_BIT(PORTB,3);
		wait_avr(freq);
		CLR_BIT(PORTB,3);
		wait_avr(freq);
	}
	
}

void play_music(struct note *song,int numNotes)
{
	for (int i = 0;  i < numNotes; i++)
	{
		if (i == 0) {
			play_note(song[i].freq, song[i].duration);
		}
		
		
	}
}