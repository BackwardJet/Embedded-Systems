
#include <stdio.h>
#include "display.h"
#include "avr.h"
#include "lcd.h"


char buf[17];
int hours = 23;   //let these be default factory settings
int minutes = 59;
int seconds = ;
int month = 4;
int day = 20;
int year = 2016;

unsigned char pressed(int r, int c)
{
	DDRC = 0x00;
	PORTC = 0x00;

	SET_BIT(PORTC, r);
	SET_BIT(DDRC, c + 4);
	CLR_BIT(PORTC, c + 4);

	if(!GET_BIT(PINC, r))
		return 1;
	return 0;
}

unsigned char get_key()
{
	unsigned char r, c;
	for (r = 0; r < 4; ++r) {
		for (c = 0; c < 4; ++c) {
			if (pressed(r, c))
				return (r * 4) + c + 1; // 1 thru 16
		}
	}
	return 0;
}

void start()  //run plus inc sec;
{
	unsigned char key = get_key();
	printdate();
	
	seconds++;

	if (seconds == 60)
	{
		seconds = 0;
		minutes++;
	}
	if (minutes == 60)
	{
		minutes = 0;
		hours++;
	}
	if (hours == 24)
	{
		hours = 0;
		updatedate();
	}

	printtime(hours, minutes, seconds);
	wait_avr(1000);
	pos_lcd(1, 0);
}


void updatedate() //carry over from time
{  
	// April only has 30 days, but the distinction between 31 days
	//   and 30 days is not a requirement for this project, so 
	//   I am assuming every month has 30 days. 
	day++;

	if (day == 30)
	{
		day = 1;
		month++;
	}
	if (month == 12)
	{
		month = 1;
		year++;
	}

	printdate(month, day, year);
}




void printtime() // 04:20:20
{
	//check everything for double digits and 
	//    pad 0 in front as necessary.
	if (hours >= 10)
	{
		if (minutes >= 10)
		{
			if (seconds >= 10)
			{
				sprintf(buf, "%2d:%2d:%2d", hours, minutes, seconds);
			}
			else // if (seconds < 10)
			{
				sprintf(buf, "%2d:%2d:0%d", hours, minutes, seconds);
			}
		}
		else // if (minutes < 10)
		{
			if (seconds >= 10)
			{
				sprintf(buf, "%2d:0%d:%2d", hours, minutes, seconds);
			}
			else // if (seconds < 10)
			{
				sprintf(buf, "%2d:0%d:0%d", hours, minutes, seconds);
			}
		}
	}
	else // if (hours < 10)
	{
		if (minutes >= 10)
		{
			if (seconds >= 10)
			{
				sprintf(buf, "0%d:%2d:%2d", hours, minutes, seconds);
			}
			else // if (seconds < 10)
			{
				sprintf(buf, "0%d:%2d:0%d", hours, minutes, seconds);
			}
		}
		else // if (minutes < 10)
		{
			if (seconds >= 10)
			{
				sprintf(buf, "0%d:0%d:%2d", hours, minutes, seconds);
			}
			else // if (seconds < 10)
			{
				sprintf(buf, "0%d:0%d:0%d", hours, minutes, seconds);
			}
		}
	}
	puts_lcd2(buf);
}



void printdate()
{
	//check month and day for double digits and 
	//    pad 0 in front as necessary.
	if (month >= 10)
	{
		if (day >= 10)
		{
			sprintf(buf, "%2d/%2d/%4d", month, day, year);
		}
		else // if (day < 10)
		{
			sprintf(buf, "%2d/0%d/%4d", month, day, year);
		}
	}
	else // if (month < 10)
	{
		if (day >= 10)
		{
			sprintf(buf, "0%d/%2d/%4d", month, day, year);
		}
		else // if (day < 10)
		{
			sprintf(buf, "0%d/0%d/%4d", month, day, year);
		}
	}

  	pos_lcd(0, 0);
	puts_lcd2(buf);
	pos_lcd(1, 0);
}


void incdec(unsigned char key)
{
	if (key == 1) // + month
	{
		if (month == 12)
			month = 1;
		else 
			month++;
	}
	else if (key == 2) // + day
	{	
		if (day == 30)
			day = 1;
		else
			day++;
	}
	else if (key == 3) // + year
	{
		year++;
	}
	else if (key == 4) // + hour
	{ 
		if (hours == 23)
			hours = 1;
		else
			hours++;
	}
	else if (key == 5) // - month
	{ 
		if (month == 1)
			month = 12;
		else
			month--;	
	}
	else if (key == 6) // - day
	{ 
		if (day == 1)
			day = 30;
		else
			day--;
	}
	else if (key == 7) // - year
	{ 
		year--;
	}
	else if (key == 8) // - hour
	{ 
		if (hours == 1)
			hours = 23;
		else
			hours--;
	}
	else if (key == 9) // + min
	{ 
		if (minutes == 59)
			minutes = 0;
		else
			minutes++;
	}
	else if (key == 10) // + sec
	{
		if (seconds == 59)
			seconds = 0;
		else
			seconds++;
	}
	else if (key == 13) // - min
	{
		if (minutes == 0)
			minutes = 59;
		else
			minutes--;
	}
	else if (key == 14)  // - sec
	{
		if (seconds == 0)
			seconds = 59;
		else
			seconds--;
	}
	
}


void setit() {
	// unsigned char key = get_key();
	unsigned char key = get_key();

	while(1)
	{
		key = get_key();
		printdate(); 
		printtime();
		wait_avr(500);
		if (key == 16) {
			break;
		}
		incdec(key);
	}
		
}





