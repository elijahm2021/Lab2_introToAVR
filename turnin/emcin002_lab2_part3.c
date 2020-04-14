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

enum States {Start, PARKING} state;
unsigned char tmpA = 0x00;
unsigned char tmpC = 0x00;
unsigned char cntavail = 0x00;

void Tick() {
	switch(state) {
		case Start:
			state = PARKING;
			break;
		case PARKING:	
			break;
		default:
			break;
	}
	switch(state) {	
		case Start:
			break;
		case PARKING:
			cntavail = 0x0F - tmpA;
			tmpC = cntavail;
			if (tmpC == 0x00) {
				tmpC = 0x80;
			}
			break;
		default:
			break;
	}
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	state = Start;
	while(1) {
		tmpA = PINA;
		Tick();
		PORTC = tmpC;
	}
    return 1;
}