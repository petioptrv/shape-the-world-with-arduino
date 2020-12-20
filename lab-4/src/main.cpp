//
// Created by Petio Petrov on 2020-12-13.
//

#include <avr/io.h>

void init_ports();
void led_off();
void red();
void green();
void blue();
bool sw1();
bool sw2();

int main()
{
    init_ports();

    while (1) {
        if (sw1()) {
            if (sw2()) {
				led_off();
                blue();
            } else {
				led_off();
                red();
            }
        } else if (sw2()) {
			led_off();
            green();
        } else {
            led_off();
        }
    };
}

void init_ports() {
    DDRB  |= 0x0E;
    PORTB &= ~(0x0E);
    DDRD  |= 0x0C;
    PORTD |= 0x0C;
}

void led_off() {
    PORTB &= ~(0x0E);
}

void red() {
    PORTB |= 0x08;
}

void green() {
    PORTB |= 0x04;
}

void blue() {
    PORTB |= 0x02;
}

bool sw1() {
    return ~PIND & 0x04;
}

bool sw2() {
    return ~PIND & 0x08;
}
