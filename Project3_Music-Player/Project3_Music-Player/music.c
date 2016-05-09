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
		if ((i > 0) && (song[i].freq == song[i-1].freq)) {
			// int delay = song[i].duration * 0.01;
			wait_avr(5);
		}
		play_note(song[i].freq, song[i].duration);
		
		
	}
}

void playHotCrossBuns() {
	//hot cross buns: bb aa gggg bb aa gggg g g g g a a a a gg bb aa
	int numNotesCross = 17;

	struct note hot_cross_buns[] = {
		{101.2391674,493.88}, // b
		{113.6363636,440}, // a
		{127.5510204,392*2}, // g for 2 seconds
		{101.2391674,493.88},
		{113.6363636,440},
		{127.5510204,392*2},
		{127.5510204,392/2},
		{127.5510204,392/2},
		{127.5510204,392/2},
		{127.5510204,392/2},
		{113.6363636,440/2},
		{113.6363636,440/2},
		{113.6363636,440/2},
		{113.6363636,440/2},
		{101.2391674,493.88},
		{113.6363636,440},
		{127.5510204,392*2}
	};
	   
	play_music(hot_cross_buns, numNotesCross);
}

void playABC() {
	// twinkle twinkle little star (Same as ABC's)
	// c c g g a a g f f e e d d c g g f f e e d c c g g a a g f f e e d d c
	
	int numNotesABC = 8;
	   
	struct note twinkle[] = {
		{127.5510204,392*2},
			{63.7755102,},
				{190.8396947,1},
					{63.7755102,1},
	   {113.6363636,3},
		   {127.5510204,3},
			   {170.0680272,1},
				   {127.5510204,1}
   };
   
   
   play_music(twinkle, numNotesABC);
}