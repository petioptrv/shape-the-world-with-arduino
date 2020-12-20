//
// Created by Petio Petrov on 2020-12-13.
//

#include <avr/io.h>

void init_ports();
void led_on();
void led_toggle();
bool sw();
void delay_100ms(unsigned long time);

int main(void)
{
    init_ports();
    led_on();

    while (1) {
        delay_100ms(1);
        if (sw()) {
            led_toggle();
        } else {
            led_on();
        }
    }
}

void delay_100ms(unsigned long time)
{
    unsigned long i;
    while (time>0) {
        i = 266666;  // this number means 100ms
        while (i>0) {
            i = i-1;
        }
        time = time-1; // decrements every 100 ms
    }
}

void init_ports()
{
    DDRB  |= 0x38;
    PORTB &= ~0x38;
    DDRD  |= 0x04;
    PORTD |= 0x04;
}

void led_on()
{
    PORTB |= 0x38;
}

void led_toggle()
{
    PORTB = (PORTB & ~0x38)|(~PORTB & 0x38);
}

bool sw()
{
    return ~PIND & 0x04;
}
