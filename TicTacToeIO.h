#define F_CPU 1000000 // CPU speed

#include <avr/io.h>
#include <util/delay.h>

#ifndef TicTacToeIO_h
#define TicTacToeIO_h

#define OFF 0
#define RED 1
#define BLUE 2
#define GREEN 3

#define PinOn(port,pin) port |= (1<<pin)
#define PinOff(port,pin) port &= ~(1<<pin)

#define redLEDOn(port,redPin,bluePin) { PinOn(port,redPin); PinOff(port, bluePin); }
#define blueLEDOn(port,redPin,bluePin) { PinOff(port,redPin); PinOn(port, bluePin); }
#define LEDOff(port,redPin,bluePin) { PinOff(port,redPin); PinOff(port, bluePin); }

class TicTacToeIO
{
private:
	TicTacToeIO();
public:
	static TicTacToeIO* GetInstance();
	
	int getButton();
	void setLED(int pin, int color);
	void setStatus(int color);
	bool changeModePressed();
};

#endif
