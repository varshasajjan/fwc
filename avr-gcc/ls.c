#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

// Reads input pins 2-5 (PD2-PD5)
uint8_t read_inputs() {
    uint8_t value = 0;
    if (PIND & (1 << PD2)) value |= 1 << 0; // Pin 2 → bit0
    if (PIND & (1 << PD3)) value |= 1 << 1; // Pin 3 → bit1
    if (PIND & (1 << PD4)) value |= 1 << 2; // Pin 4 → bit2
    if (PIND & (1 << PD5)) value |= 1 << 3; // Pin 5 → bit3
    return value;
}

// Outputs 4-bit BCD value to pins 2-5 (inputs of 7447)
void output_bcd(uint8_t val) {
    // Clear bits 2-5
    PORTD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5));
    // Set bits 2-5 as per the lower 4 bits of val
    PORTD |= ((val & 0x0F) << PD2);
}

int main(void) {
    // Configure pins 2-5 as input for reading switches
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5));
    // Enable pull-downs externally or use internal pull-ups if wiring accordingly

    // Configure pins 2-5 as output to send data to 7447
    // (Assuming you are reconfiguring temporarily or using separate pins for output)
    // If same pins used, code must switch DDR dynamically (requires voltage level handling)
    // For simplicity here, assuming separate pins 6-9 for 7447 inputs, adjust as needed
    // If same pins, you may need to restructure hardware or code

    while (1) {
        uint8_t val = read_inputs();

        if (val == 7 || val == 8) {
            output_bcd(val);   // Display digit 7 or 8 on 7-seg via 7447
        } else {
            // 7447 can't display 11, clear powers to blank 7-seg
            output_bcd(0x0F); // commonly blank or off
        }
        _delay_ms(100);
    }
}
