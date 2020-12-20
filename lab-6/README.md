# Lab 6

This is a re-implementation of the chapter 6 lab from the excellent
UTexas course [Embedded Systems - Shape The World](http://users.ece.utexas.edu/~valvano/Volume1/E-Book/)
on the Arduino Uno (ATmega328P) board.

The `Makefile` and the supporting files in the `arduino` directory
are adapted from the [Nodate](https://github.com/MayaPosch/Nodate) project.

# Description
The Arduino UNO is clocked at [16 MHz](https://store.arduino.cc/usa/arduino-uno-rev3), which is equivalent to the TM4C123 used in the course. I was not able to find phase lock loop (pll) capabilities on the Arduino UNO. That being said, I have decided to modify the delay function by replacing the 80MHz with the Arduino's 16MHz, yielding:

    void Delay100ms(unsigned long time){
      unsigned long i;
      while(time > 0){
        i = 266666;  // this number means 100ms
        while(i > 0){
          i = i - 1;
        }
        time = time - 1; // decrements every 100 ms
      }
    }

This calculation did not prove to be totally accurate, but I don't have enough information at the moment to make the proper adjustment.

After some searching, it looks like bit-specific addressing is not present on the ATmega328P. By following the trail of `PORB` from `iom328p.h`, import from `io.h`, we see that `PORTB` is mapped to memory address `0x25`, preceeded immediately by `DDRB` at `0x24` and followed immediately by `PINC` at `0x26`. This leaves no space for bit-specific memory mapping.

# Schematic

![schematic](https://github.com/petioptrv/shape-the-world-with-arduino/blob/master/lab-6/images/Lab-6.png?raw=true)

# Installation
## Linux

    sudo apt-get install gcc-avr
    sudo apt-get install avr-libc
    sudo apt-get install avrdude

# Building & Uploading
## Linux

`cd` into the project directory.

    make
    make flash COM_PORT=/dev/ttyACM0


