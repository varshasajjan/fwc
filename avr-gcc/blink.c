#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t read_inputs() {
    // Pins: 2, 3, 4, 5 as inputs
    return ((PIND >> 2) & 0x01) | ((PIND >> 2) & 0x02) | ((PIND >> 3) & 0x04) | ((PIND >> 4) & 0x08);
}

int main(void) {
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5)); // Set pins 2-5 as input
    DDRB |= (1 << PB5); // Set pin 13 as output

    while (1) {
        uint8_t value = ((PIND >> PD2) & 0x01) |
                        ((PIND >> PD3) & 0x02) |
                        ((PIND >> PD4) & 0x04) |
                        ((PIND >> PD5) & 0x08);

        // Check if minterm is 7, 8, or 11
        if (value == 7 || value == 8 || value == 11) {
            PORTB |= (1 << PB5); // LED ON
        } else {
            PORTB &= ~(1 << PB5); // LED OFF
        }
        _delay_ms(50);
    }
}
