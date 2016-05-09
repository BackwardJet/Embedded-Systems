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
   puts_lcd2("PROJECT 3");
   
   
   /*
   
   int n_twinkle = 8;
   
   struct note twinkle[] = {{127.5510204,392*2},{63.7755102,},{190.8396947,1},{63.7755102,1},
   {113.6363636,3},{127.5510204,3},{170.0680272,1},{127.5510204,1}
   };
   
   
   play_music(twinkle, n_twinkle);
   
   */
   
   // twinkle twinkle little star
   // c c g g a a g f f e e d d c g g f f e e d c c g g a a g f f e e d d c
   
   
   int numNotesCross = 17;
   
   //hot cross buns: bb aa gggg bb aa gggg g g g g a a a a gg bb aa

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

   return 0;

}

