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

enum States {Start, CALCULATE} state;
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;
unsigned char tmpC = 0x00;
unsigned char tmpD = 0x00;
unsigned char total_weight = 0x00;

void Tick() {
	switch(state) {
		case Start:
			state = CALCULATE;
			break;
		case CALCULATE:
			break;
		default:
			break;
	}
	switch(state) {	
		case Start:
			break;
		case CALCULATE:			
			if ((total_weight) > 140) {
				tmpD = tmpD | 0x01;
			}
			if (tmpA > tmpC && ((tmpA - tmpC) > 80)) {
				tmpD = tmpD | 0x02;
			}
			if (tmpC > tmpA && ((tmpC-tmpA) > 80)) {
				tmpD = tmpD | 0x02;
			}
			tmpD = tmpD | (total_weight << 2);
			break;
		default:
			break;
	}
}

int main(void) {
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	state = Start;
	while(1) {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;
		total_weight = tmpA + tmpB + tmpC;
		Tick();
		PORTD = tmpD;
	}
    return 1;
}
