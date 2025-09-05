#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

// Possible output codes
#define OUT_0    0  // Output is 0
#define OUT_1    1  // Output is 1
#define OUT_X    2  // Don't care

// FSM output table for 16 states (0–15)
// Use OUT_X for don't cares.
const uint8_t fsm_output[16] = {
    OUT_0, // 0
    OUT_0, // 1
    OUT_X, // 2: don't care
    OUT_0, // 3
    OUT_0, // 4
    OUT_0, // 5
    OUT_0, // 6
    OUT_1, // 7
    OUT_1, // 8
    OUT_0, // 9
    OUT_0, // 10
    OUT_1, // 11
    OUT_0, // 12
    OUT_X, // 13: don't care
    OUT_0, // 14
    OUT_0  // 15
};

uint8_t read_state() {
    uint8_t state = 0;
    if (PIND & (1 << PD2)) state |= 1 << 0;
    if (PIND & (1 << PD3)) state |= 1 << 1;
    if (PIND & (1 << PD4)) state |= 1 << 2;
    if (PIND & (1 << PD5)) state |= 1 << 3;
    return state;
}

int main(void) {
    DDRD &= ~((1 << PD2)|(1 << PD3)|(1 << PD4)|(1 << PD5)); // Pins as input
    DDRB |= (1 << PB5); // Pin 13 output (LED)

    while(1) {
        uint8_t state  = read_state();
        uint8_t output = fsm_output[state];

        // Here you choose what to do for 'don't care' states; LED OFF by default:
        if (output == OUT_1) {
            PORTB |= (1 << PB5);  // LED ON
        } else if (output == OUT_0) {
            PORTB &= ~(1 << PB5); // LED OFF
        } else if (output == OUT_X) {
            // For dont care: keep LED OFF, or blink, or random
            PORTB &= ~(1 << PB5);
            // Or do: PORTB ^= (1 << PB5); // Toggle for effect
        }
        _delay_ms(50);
    }
}
