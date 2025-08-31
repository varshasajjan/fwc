#include <Arduino.h>

// Connections to 74HC74
const int dataPins[4] = {2, 3, 4, 5};  // D0–D3
const int clkPin = 6;                  // Clock to latch into 74HC74

// HEX digits for -28 (in 16-bit 2’s complement)
byte digits[4] = {0xF, 0xF, 0xE, 0x4};

void latchDigit(byte value) {
  // Send 4-bit digit to 74HC74
  for (int i = 0; i < 4; i++) {
    digitalWrite(dataPins[i], (value >> i) & 0x01);
  }

  // Pulse the clock to latch
  digitalWrite(clkPin, LOW);
  delayMicroseconds(5);
  digitalWrite(clkPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(clkPin, LOW);
}

void setup() {
  for (int i = 0; i < 4; i++) pinMode(dataPins[i], OUTPUT);
  pinMode(clkPin, OUTPUT);

  // Initialize low
  digitalWrite(clkPin, LOW);
}

void loop() {
  // Scroll digits one by one
  for (int i = 0; i < 4; i++) {
    latchDigit(digits[i]);  // send digit to 74HC74 → 74LS47 → 7-seg
    delay(1000);            // show for 1 sec
  }
}
