# Lab 4 - LED & Buttons

This is a re-implementation of the chapter 4 lab from the excellent
UTexas course [Embedded Systems - Shape The World](http://users.ece.utexas.edu/~valvano/Volume1/E-Book/)
on the Arduino Uno (ATmega328P) board.

The `Makefile` and the supporting files in the `arduino` directory
are adapted from the [Nodate](https://github.com/MayaPosch/Nodate) project.

# Description

# Schematic

![schematic](https://github.com/petioptrv/shape-the-world-with-arduino/blob/master/lab-4/images/Lab-4.png?raw=true)

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


