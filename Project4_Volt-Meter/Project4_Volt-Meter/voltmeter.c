/*
 * voltmeter.c
 *
 * Created: 5/21/2016 7:47:07 PM
 *  Author: Tej Vuligonda
 */ 

#include "avr.h"
#include "voltmeter.h"
#include <stdio.h>




void init_registers() {
	// SET_BIT(ADMUX,1);
	// SET_BIT(ADMUX,6);
	
	// ADMUX = (1 << 6) | (1 << 1) | (1 << 0);
	ADMUX = (1 << REFS0);
	// ADMUX = (1 << REFS0) | (1 << MUX1) | (1 << MUX0);
	
	
	ADCSRA = (1 << ADEN) | (1 << ADSC);
	/*
	ADCSRA |= _BV (ADEN);
	Bit 7 – ADEN: Set this to binary 1 to enable the microcontroller ADC circuits, whilst binary 0 will switch it OFF.

	ADCSRA |= _BV (ADSC);
	Bit 6 – ADSC: Setting ADSC bit to binary 1 starts the conversion process. This bit clears automatically when the conversion process completes. Therefore, this bit provides an indication that the conversion has completed.
	*/
}