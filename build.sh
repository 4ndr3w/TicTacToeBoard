#!/bin/sh
 
# Compile all .cpp files into object files
avr-g++ *.cpp -c -mmcu=atmega32 -O3
# Compile all object files into one binary
avr-g++ *.o -o bin -mmcu=atmega32 -O3

# Convert binary to hex
avr-objcopy -j .text -O ihex bin TicTacToe.hex
# Flash .hex file onto the chip
avrdude -c usbtiny -p atmega32 -U flash:w:TicTacToe.hex -F

