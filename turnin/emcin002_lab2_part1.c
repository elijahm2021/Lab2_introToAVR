/*	Author: emcin002
 *  Partner(s) Name: 
 *	Lab Section: 027
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {Start, OFF, ON} state;
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;

void Tick() {
	switch(state) {
		case Start:
			state = OFF;
			break;
		case OFF:
			if (tmpA == 0x01) {
				state = ON; 
			}	
			break;
		case ON:
			if (tmpA != 0x01) {
				state = OFF;
			}
			break;
		default:
			break;
	}
	switch(state) {	
		case Start:
			break;
		case OFF:
			tmpB = 0x00;
			break;
		case ON:
			tmpB = 0x01;
			break;
		default:
			break;
	}
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	state = Start;
	while(1) {
		tmpA = PINA;
		Tick();
		PORTB = tmpB;
	}
    return 1;
}
