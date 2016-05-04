
#include <avr/io.h>
#include "avr.h"
#include "lcd.h"
#include "display.h"


int main(void)
{
	ini_lcd();	
	clr_lcd();
	pos_lcd(0, 0);
	puts_lcd2("dsaf");
	unsigned char key = get_key();
	
	while (1)
	{
		key = get_key();
		if (key == 12)
		{
			start();
		}
		if (key == 15)
		{
			setit();
		}
	}

}
