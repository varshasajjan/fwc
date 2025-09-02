#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

// Segment pins connected to Arduino pins 7,6,5,4,3,2,8 respectively
const uint8_t segment_pins[7] = {7, 6, 5, 4, 3, 2, 8};

// Digit map for 7-seg (common cathode)
// Bits g-f-e-d-c-b-a from LSB=bit0 (a) to MSB=bit6 (g)
const uint8_t digit_map[3] = {
    0x07, // 7: segments a,b,c ON
    0x7F, // 8: all segments ON
    0x7C  // 11 (B): segments c,d,e,f,g ON
};

uint8_t read_inputs() {
    uint8_t value = 0;
    if (PIND & (1 << PD2)) value |= 1 << 0; // Pin 2 → bit0
    if (PIND & (1 << PD3)) value |= 1 << 1; // Pin 3 → bit1
    if (PIND & (1 << PD4)) value |= 1 << 2; // Pin 4 → bit2
    if (PIND & (1 << PD5)) value |= 1 << 3; // Pin 5 → bit3
    return value;
}

void display_digit(uint8_t digit_index) {
    uint8_t segments = digit_map[digit_index];
    for (int i = 0; i < 7; i++) {
        if (segments & (1 << i)) {
            PORTD |= (1 << segment_pins[i]);  // Turn ON segment pin
        } else {
            PORTD &= ~(1 << segment_pins[i]); // Turn OFF segment pin
        }
    }
}

int main(void) {
    // Configure input pins 2-5 as input
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5));
    // Configure segment pins as output: 2,3,4,5,6,7,8
    DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7);
    // For pin 8, which is PB0 on Arduino Uno, configure PORTB
    DDRB |= (1 << PB0);

    while (1) {
        uint8_t val = read_inputs();
        if (val == 7) {
            display_digit(0);
        } else if (val == 8) {
            display_digit(1);
        } else if (val == 11) {
            display_digit(2);
        } else {
            // Turn off all segments if input doesn't match
            for (int i = 0; i < 7; i++) {
                if (segment_pins[i] <= PD7)
                    PORTD &= ~(1 << segment_pins[i]);
                else if (segment_pins[i] == 8)
                    PORTB &= ~(1 << PB0);
            }
        }
        _delay_ms(50);
    }
}
