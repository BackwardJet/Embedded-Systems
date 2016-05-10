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

void play_note_volume(int freq, int dur, double ratio) {
	for(int i = 0; i < (dur); i++)
	{
		SET_BIT(PORTB,3);
		wait_avr(freq*(1-ratio));
		CLR_BIT(PORTB,3);
		wait_avr(freq*ratio);
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

void play_music_volume(struct note *song,int numNotes, double ratio)
{
	for (int i = 0;  i < numNotes; i++)
	{
		if ((i > 0) && (song[i].freq == song[i-1].freq)) {
			// int delay = song[i].duration * 0.01;
			wait_avr(5);
		}
		play_note_volume(song[i].freq*2, song[i].duration, ratio);
		
		
	}
}

void playHotCrossBuns(int tempo, double volumeRatio) {
	//hot cross buns: bb aa gggg bb aa gggg g g g g a a a a gg bb aa
	int numNotesCross = 17;

	struct note hot_cross_buns[] = {
		{101.2391674,493.88/tempo}, // b
		{113.6363636,440/tempo}, // a
		{127.5510204,(392*2)/tempo}, // g for 2 seconds
		{101.2391674,493.88/tempo},
		{113.6363636,440/tempo},
		{127.5510204,(392*2)/tempo},
		{127.5510204,(392/2)/tempo},
		{127.5510204,(392/2)/tempo},
		{127.5510204,(392/2)/tempo},
		{127.5510204,(392/2)/tempo},
		{113.6363636,(440/2)/tempo},
		{113.6363636,(440/2)/tempo},
		{113.6363636,(440/2)/tempo},
		{113.6363636,(440/2)/tempo},
		{101.2391674,493.88/tempo},
		{113.6363636,440/tempo},
		{127.5510204,(392*2)/tempo}
	};
	   
	play_music_volume(hot_cross_buns, numNotesCross, volumeRatio);
}

void playHotCrossBunsVolume(int tempo) {
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
	
	play_music_volume(hot_cross_buns, numNotesCross, 0.5);
}

void playABC(int tempo, double volumeRatio) {
	// twinkle twinkle little star (Same as ABC's)
	// c c g g a a gg f f e e d d cc g g f f e e dd c c g g a a gg f f e e d d cc
	
	int numNotesABC = 35;
	   
	struct note twinkle[] = {
		{191.1095822,261.63/tempo}, //c
		{191.1095822,261.63/tempo},
		{127.5510204,392/tempo}, //g
		{127.5510204,392/tempo},
		{113.6363636,440/tempo}, //a
		{113.6363636,440/tempo},
		{127.5510204,(392*2)/tempo},
		{143.1721215,349.23/tempo}, //f
		{143.1721215,349.23/tempo},
		{151.6852228,329.63/tempo}, //e
		{151.6852228,329.63/tempo},
		{170.2649322,293.66/tempo}, //d
		{170.2649322,293.66/tempo},
		{191.1095822,(261.63*2)/tempo},
		{127.5510204,392/tempo}, //g
		{127.5510204,392/tempo},
		{143.1721215,349.23/tempo}, //f
		{143.1721215,349.23/tempo},
		{151.6852228,329.63/tempo}, //e
		{151.6852228,329.63/tempo},
		{170.2649322,(293.66*2)/tempo},
		{191.1095822,261.63/tempo}, //c
		{191.1095822,261.63/tempo},
		{127.5510204,392/tempo}, //g
		{127.5510204,392/tempo},
		{113.6363636,440/tempo}, //a
		{113.6363636,440/tempo},
		{127.5510204,392*2/tempo},
		{143.1721215,349.23/tempo}, //f
		{143.1721215,349.23/tempo},
		{151.6852228,329.63/tempo}, //e
		{151.6852228,329.63/tempo},
		{170.2649322,293.66/tempo}, //d
		{170.2649322,293.66/tempo},
		{191.1095822,(261.63*2)/tempo},
				 
   };
   
   
   play_music_volume(twinkle, numNotesABC, volumeRatio);
}