#include "TicTacToeIO.h"

TicTacToeIO* TicTacToeIO::GetInstance()
{
	static TicTacToeIO instance;
	return &instance;
}


TicTacToeIO::TicTacToeIO()
{
	// Disable JTAG interface that uses some pins in PORTC
	MCUCSR=0x80; MCUCSR=0x80;
	
	// Set the pins connected to red LED pins to output
	DDRB |= (1<<PB3);
	DDRB |= (1<<PB1);
	DDRC |= (1<<PC7);
	DDRA |= (1<<PA1);
	DDRB |= (1<<PB7);
	DDRB |= (1<<PB5);
	DDRA |= (1<<PA7);
	DDRA |= (1<<PA5);
	DDRA |= (1<<PA3);
	
	// Set the pins connected to blue LED pins to output
	DDRB |= (1<<PB2);
	DDRB |= (1<<PB0);
	DDRC |= (1<<PC6);
	DDRA |= (1<<PA0);
	DDRB |= (1<<PB6);
	DDRB |= (1<<PB4);
	DDRA |= (1<<PA6);
	DDRA |= (1<<PA4);
	DDRA |= (1<<PA2);
	
	// Status LED
	DDRD |= (1<<PD2);
	DDRD |= (1<<PD3);
	DDRD |= (1<<PD4);
}

int TicTacToeIO::getButton()
{
	if ( bit_is_clear(PINC, PC5) ) return 0;
	if ( bit_is_clear(PINC, PC4) ) return 3;
	if ( bit_is_clear(PINC, PC3) ) return 6;
	if ( bit_is_clear(PINC, PC2) ) return 1;
	if ( bit_is_clear(PINC, PC1) ) return 4;
	if ( bit_is_clear(PINC, PC0) ) return 7;
	if ( bit_is_clear(PIND, PC7) ) return 2;
	if ( bit_is_clear(PIND, PC6) ) return 5;
	if ( bit_is_clear(PIND, PC5) ) return 8;
	return -1;
}

bool TicTacToeIO::changeModePressed()
{
	return bit_is_clear(PINC, PC5)&&bit_is_clear(PINC, PC2);
}

void TicTacToeIO::setLED(int pin, int color)
{
	switch ( pin )
	{
		case 0:
			if ( color == RED ) { PinOn(PORTB, PB3); PinOff(PORTB, PB2); }
			else if ( color == BLUE ) { PinOff(PORTB, PB3); PinOn(PORTB, PB2); }
			else { PinOff(PORTB, PB3); PinOff(PORTB, PB2); }
		break;

		case 3:
			if ( color == RED ) { PinOn(PORTB, PB1); PinOff(PORTB, PB0); }
			else if ( color == BLUE ) { PinOff(PORTB, PB1); PinOn(PORTB, PB0); }
			else { PinOff(PORTB, PB1); PinOff(PORTB, PB0); }
		break;

		case 6:
			if ( color == RED ) { PinOn(PORTC, PC7); PinOff(PORTC, PC6); }
			else if ( color == BLUE ) { PinOff(PORTC, PC7); PinOn(PORTC, PC6); }
			else { PinOff(PORTC, PC7); PinOff(PORTC, PC6); }
		break;

		case 1:
			if ( color == RED ) { PinOn(PORTA, PA1); PinOff(PORTA, PA0); }
			else if ( color == BLUE ) { PinOff(PORTA, PA1); PinOn(PORTA, PA0); }
			else { PinOff(PORTA, PA1); PinOff(PORTA, PA0); }
		break;

		case 4:
			if ( color == RED ) { PinOn(PORTB, PB7); PinOff(PORTB, PB6); }
			else if ( color == BLUE ) { PinOff(PORTB, PB7); PinOn(PORTB, PB6); }
			else { PinOff(PORTB, PB7); PinOff(PORTB, PB6); }
		break;

		case 7:
			if ( color == RED ) { PinOn(PORTB, PB5); PinOff(PORTB, PB4); }
			else if ( color == BLUE ) { PinOff(PORTB, PB5); PinOn(PORTB, PB4); }
			else { PinOff(PORTB, PB5); PinOff(PORTB, PB4); }
		break;

		case 2:
			if ( color == RED ) { PinOn(PORTA, PA7); PinOff(PORTA, PA6); }
			else if ( color == BLUE ) { PinOff(PORTA, PA7); PinOn(PORTA, PA6); }
			else { PinOff(PORTA, PA7); PinOff(PORTA, PA6); }
		break;

		case 5:
			if ( color == RED ) { PinOn(PORTA, PA5); PinOff(PORTA, PA4); }
			else if ( color == BLUE ) { PinOff(PORTA, PA5); PinOn(PORTA, PA4); }
			else { PinOff(PORTA, PA5); PinOff(PORTA, PA4); }
		break;

		case 8:
			if ( color == RED ) { PinOn(PORTA, PA3); PinOff(PORTA, PA2); }
			else if ( color == BLUE ) { PinOff(PORTA, PA3); PinOn(PORTA, PA2); }
			else { PinOff(PORTA, PA3); PinOff(PORTA, PA2); }
		break;
	}	
}

void TicTacToeIO::setStatus(int color)
{
	if ( color == RED ) { PinOn(PORTD, PD2); PinOff(PORTD, PD3); PinOff(PORTD, PD4); }
	else if ( color == BLUE ) { PinOff(PORTD, PD2); PinOn(PORTD, PD3); PinOff(PORTD, PD4); }
	else if ( color == GREEN ) { PinOff(PORTD, PD2); PinOff(PORTD, PD3); PinOn(PORTD, PD4); }
	else { PinOff(PORTD, PD2); PinOff(PORTD, PD3); PinOff(PORTD, PD4); }
}

