/*
 * File:   main.c
 * Author: Safaa
 *
 * Created on May 1, 2020, 11:27 AM
 */

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "mTimer.h"

#define LED    0

//30 times per second

ISR(TIMER0_OVF_vect) {
    static int _1sec = 0;
    _1sec++;
    if (_1sec == 31) {
        // Once every on second
        PORTC ^= (1 << LED); // LED Toggle
        _1sec = 0;
    }
}

int main(void) {
    /* Replace with your application code */
    
    DDRC |= (1 << LED);
    PORTC &= ~(1 << LED);


    Timer0_init(NormalMode, OC0_DIS, CLK_io_PS1024);

    sei(); // Global Interrupt Enable
    while (1) {


    }
}
