#include <Arduino.h>

// Connect Arduino pins to 74LS47 inputs (A, B, C, D)
const int bcdPins[4] = {2, 3, 4, 5};  // A=2, B=3, C=4, D=5

void displayDigit(int digit) {
  // Write 4-bit binary of digit to pins
  for (int i = 0; i < 4; i++) {
    digitalWrite(bcdPins[i], (digit >> i) & 0x1);
  }
}

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(bcdPins[i], OUTPUT);
  }
}

void loop() {
  // -28 (16-bit 2's complement) = 0xFFE4
  int hexValues[4] = {15, 15, 14, 4};  // F, F, E, 4

  for (int i = 0; i < 4; i++) {
    displayDigit(hexValues[i]);
    delay(1000);  // Show each digit for 1 sec
  }
}
