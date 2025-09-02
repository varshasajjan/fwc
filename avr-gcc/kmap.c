#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

uint8_t read_inputs() {
    uint8_t value = 0;
    if (PIND & (1 << PD2)) value |= 1 << 0; // Pin 2 → bit 0
    if (PIND & (1 << PD3)) value |= 1 << 1; // Pin 3 → bit 1
    if (PIND & (1 << PD4)) value |= 1 << 2; // Pin 4 → bit 2
    if (PIND & (1 << PD5)) value |= 1 << 3; // Pin 5 → bit 3
    return value;
}

int main(void) {
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5)); // Inputs pins 2-5
    DDRB |= (1 << PB5); // Pin 13 as output for LED

    while (1) {
        uint8_t val = read_inputs();

        // Output function f = Σ(7, 8, 11)
        if (val == 7 || val == 8 || val == 11) {
            PORTB |= (1 << PB5);  // Turn LED ON
        } else {
            PORTB &= ~(1 << PB5); // Turn LED OFF
        }

        _delay_ms(50);
    }
}
