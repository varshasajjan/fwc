#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

// Assume pins 2-5 as input (switches), 6-9 as output BCD
uint8_t read_inputs() {
    uint8_t value = 0;
    if (PIND & (1 << PD2)) value |= 1 << 0;
    if (PIND & (1 << PD3)) value |= 1 << 1;
    if (PIND & (1 << PD4)) value |= 1 << 2;
    if (PIND & (1 << PD5)) value |= 1 << 3;
    return value;
}

void output_bcd(uint8_t bcd) {
    // Output BCD on 6-9 (adjust as needed)
    for (uint8_t i = 0; i < 4; i++) {
        if ((bcd >> i) & 1) PORTD |=  (1 << (PD6+i));
        else                PORTD &= ~(1 << (PD6+i));
    }
}

int main(void) {
    DDRD &= ~0b00111100; // Pins 2-5 as input
    DDRD |=  0b11110000; // Pins 6-9 as output

    while (1) {
        uint8_t val = read_inputs();
        if (val == 7 || val == 8) {
            output_bcd(val); // BCD for 7 or 8
        } else if (val == 11) {
            output_bcd(11);  // "B" is not displayable, will appear as "1" on L47
        } else {
            output_bcd(0x0F); // Blank or unused value
        }
        _delay_ms(100);
    }
}
