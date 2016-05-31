
/*
 * Project4_Volt-Meter.c
 *
 * Created: 5/11/2016 5:16:28 PM
 * Author : Tej Vuligonda
 */ 

#include "avr.h"
#include "lcd.h"
#include "keypad.h"
//#include "voltmeter.h"
#include <stdio.h>
#include <string.h>

char a[5] = "12";
char b[5] = "2111";
char c[5] = "2121";
char d[5] = "211";
char e[5] = "1";
char f[5] = "1121";
char g[5] = "221";
char h[5] = "1111";
char i[5] = "11";
char j[5] = "1222";
char k[5] = "212";
char l[5] = "1211";
char m[5] = "22";
char n[5] = "21";
char o[5] = "222";
char p[5] = "1221";
char q[5] = "2212";
char r[5] = "121";
char s[5] = "111";
char t[5] = "2";
char u[5] = "112";
char v[5] = "1112";
char w[5] = "122";
char x[5] = "2112";
char y[5] = "2122";
char z[5] = "2211";

//Arrays to store phrase to put on LCD
char line1[17];
char line2[17];


// ascii for . is 46
// ascii for - is 45


int get_morse_char(int* gmc)
{
	puts_lcd2("getting chars");
	//static int morse_char[5];
	for (;;) {
		// start sampling
		int counter = 0;
		while (1) {
			unsigned char key_again = get_key();
			wait_avr(100);
			if (counter >= 5)
				return counter;
			if (key_again == 1) {
				gmc[counter] = 1;
				counter++;
			}
			else if (key_again == 2)
			{
				gmc[counter] = 2;
				counter++;
			}
			else if (key_again == 15)
				return counter;
		}
	}
	
}

void get_morse_word(int* gmc,int gmc_size, char* gmw, int gmw_size)
{
	char buf[1];
	char letter[5];
	if(!gmc || gmw_size < 1 || gmc_size < 1)
		return;
	else{
		for(int i = 0; i < gmc_size; i++)
		{
			sprintf(buf, "%d", gmc[i]);
			strcat(letter, buf);
		}
			
		if (strcmp(letter, a)){
			strcat(gmw, "A");			
		}
	}
}

int main(void)
{
	ini_lcd();
	set_lcd_lines("Project 5", "Started");
	// keypad: 1 (key == 1) -> short press
	// keypad: 2 (key == 2) -> long press?
	// keypad: # (key == 15) -> separate letters
	// keypad: D (key == 16) -> separate words
	// keypad: * (key == 13) -> end session
		
	//stores char
	int gmc[5];
	int gmc_size;
	//stores word
	char gmw[17];
	
	
	for (;;) {
		unsigned char key = get_key();
		wait_avr(150);
		if (key == 13) {
			break;
		}
		// start sampling
		else if (key == 4)
		{
			clr_lcd();
			while(1)
			{
				gmc_size = get_morse_char(gmc);
				clr_lcd();
				get_morse_word(gmc, gmc_size, gmw, 17);
				puts_lcd2(gmw);
				wait_avr(500);
			}
		}		
	}
	return 0;
}



