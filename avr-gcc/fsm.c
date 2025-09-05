#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

// Read 4-bit state from pins 2-5
uint8_t read_state() {
    uint8_t state = 0;
    if (PIND & (1 << PD2)) state |= 1 << 0;
    if (PIND & (1 << PD3)) state |= 1 << 1;
    if (PIND & (1 << PD4)) state |= 1 << 2;
    if (PIND & (1 << PD5)) state |= 1 << 3;
    return state;
}

// FSM output truth table for 16 states (0–15)
const uint8_t fsm_output[16] = {
    0, // 0
    0, // 1
    0, // 2
    0, // 3
    0, // 4
    0, // 5
    0, // 6
    1, // 7
    1, // 8
    0, // 9
    0, // 10
    1, // 11
    0, // 12
    0, // 13
    0, // 14
    0  // 15
};

int main(void) {
    DDRD &= ~((1 << PD2)|(1 << PD3)|(1 << PD4)|(1 << PD5)); // Pins 2-5 input
    DDRB |= (1 << PB5); // Pin 13 output (LED)

    while(1) {
        uint8_t state = read_state();   // FSM current state
        uint8_t output = fsm_output[state]; // Output from lookup table
        if (output) {
            PORTB |= (1 << PB5); // LED ON
        } else {
            PORTB &= ~(1 << PB5); // LED OFF
        }
        _delay_ms(50);
    }
}
