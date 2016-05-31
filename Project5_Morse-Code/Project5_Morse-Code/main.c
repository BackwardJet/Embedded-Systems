
//-#include "avr.h"
//-#include "lcd.h"
//-#include "keypad.h"
//#include "voltmeter.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[5] = "12";
char b[5] = "2111";




char line1[17];
char line2[17];

struct letter {
	char key[1];
	unsigned int value;
};

struct array {
	int list[5];
	int capacity;
	int length;
};

struct letter letters[26] = {
{'A',12},
{'B',2111},
{'C',2121},
{'D',211},
{'E',1},
{'F',1121},
{'G',221},
{'H',1111},
{'I',11},
{'J',1222},
{'K',212},
{'L',1211},
{'M',22},
{'N',21},
{'O',222},
{'P',1221},
{'Q',2212},
{'R',121},
{'S',111},
{'T',2},
{'U',112},
{'V',1112},
{'W',122},
{'X',2112},
{'Y',2122},
{'Z',2211}
};
struct letter A = {
	'A',
	12
};
struct letter B = {
	'B',
	2111
};
struct letter C = {
	'C',
	2121
};
struct letter D = {
	'D',
	211
};
struct letter E = {
	'E',
	1
};
struct letter F = {
	'F',
	1121
};
struct letter G = {
	'G',
	221
};
struct letter H = {
	'H',
	1111
};
struct letter I = {
	'I',
	11
};
struct letter J = {
	'J',
	1222
};
struct letter K = {
	'K',
	212
};
struct letter L = {
	'L',
	1211
};
struct letter M = {
	'M',
	22
};
struct letter N = {
	'N',
	21
};
struct letter O = {
	'O',
	222
};
struct letter P = {
	'P',
	1221
};
struct letter Q = {
	'Q',
	2212
};
struct letter R = {
	'R',
	121
};
struct letter S = {
	'S',
	111
};
struct letter T = {
	'T',
	2
};
struct letter U = {
	'U',
	112
};
struct letter V = {
	'V',
	1112
};
struct letter W = {
	'W',
	122
};
struct letter X = {
	'X',
	2112
};
struct letter Y = {
	'Y',
	2122
};
struct letter Z = {
	'Z',
	2211
};

//letters[0].key = A.key;
//letters[0].value = A.value;

// ascii for . is 46
// ascii for - is 45


//-int * get_morse_char()
struct array get_morse_char()
{
	//-puts_lcd2("getting chars");
	printf("getting chars\n");
	static int morse_char[5];
//struct array mc = {morse_char,5,counter};
for (;;) {
	// start sampling
	int counter = 0;
	while (1) {
		//-unsigned char key_again = get_key();
		//-wait_avr(100);
		//char temp[3];
		int key_again;
		scanf("%d",&key_again);
		if (key_again == 1) {
			printf("key 1 pressed\n");
			morse_char[counter] = 1;
			counter++;
		}
		else if (key_again == 2)
		{
			printf("key 2 pressed\n");
			morse_char[counter] = 2;
			counter++;
		}
		//-else if (key_again == 15)
		else if (key_again == 3)
		{
			printf("key 3 pressed\n");
			struct array mc;
			memcpy(mc.list, morse_char, sizeof(morse_char));
			mc.capacity = 5;
			mc.length = counter;
			printf("Counter: %d",counter);
			return mc;
		}
	}
}

}



int main(void)
{
	//-ini_lcd();
	//-set_lcd_lines("Project 5", "Started");
	printf("Project 5 started\n");
	// keypad: 1 (key == 1) -> short press
	// keypad: 2 (key == 2) -> long press?
	// keypad: # (key == 15) -> separate letters
	// keypad: D (key == 16) -> separate words
	// keypad: * (key == 13) -> end session

	 //- int *p;
	 char buf[5];
	 //-for (;;) {
	 while(1) {
		 //-unsigned char key = get_key();
		 //-wait_avr(150);
	 	 printf("Dask\n");
	 	 char temp[1];
		 scanf("%c",temp);
		 printf("temp: %s\n",temp);
		 unsigned char key = atoi(temp);
		 if (key == 13) {
		 	 printf("key 13 and we done");
			 break;
		 }
		 else if (key == 4)
		 {
			//-clr_lcd();
			printf("key 4 pressed\n");
			//-p = get_morse_char();
			struct array p = get_morse_char();
			printf("\nDone\n");
			//-clr_lcd();
			// sprintf(buf,"%d",p.list[0]);
			if (p.length == 1) {
				sprintf(buf,"%d",p.list[0]);
				printf("Value: %s\n", buf); 
			}
			else if (p.length == 2) {
				sprintf(buf,"%d%d",p.list[0],p.list[1]);
				printf("Value: %s\n", buf); 
			} 
			else if (p.length == 3) {
				printf("length is equal to 3\n"); 
				sprintf(buf,"%d%d%d",p.list[0],p.list[1],p.list[2]);
				printf("Value: %s\n", buf); 
			} 
			else if (p.length == 4) {
				sprintf(buf,"%d%d%d%d",p.list[0],p.list[1],p.list[2],p.list[3]);
				printf("Value: %s\n", buf); 
			} 
			//-sprintf(buf, "%d%d\n", p[0], p[1]);
			//-puts_lcd2(buf);
			//printf(buf);
			int temp = atoi(buf);
			for (int i = 0; i < 26; i++) {
				struct letter theLetter = letters[i];
				if (temp == theLetter.value) {//-strcmp(buf, a)){
					//-clr_lcd();
					//-puts_lcd2("A");
					//sprintf(line1, "%s", A.key);
					printf(theLetter.key);
					break;
				}
			}
		}
	
		
	}
	return 0;
}



