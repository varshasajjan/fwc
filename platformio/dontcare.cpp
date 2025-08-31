#include <Arduino.h>

// Connect Arduino pins to A-D inputs of 74LS47
int D0 = 2;  // A (LSB)
int D1 = 3;  // B
int D2 = 4;  // C
int D3 = 5;  // D (MSB)

// Digits of -28 in hex = F F E 4
byte digits[4] = {0xF, 0xF, 0xE, 0x4};

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
}

void showDigit(byte num) {
  digitalWrite(D0, num & 0x1);
  digitalWrite(D1, (num >> 1) & 0x1);
  digitalWrite(D2, (num >> 2) & 0x1);
  digitalWrite(D3, (num >> 3) & 0x1);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    showDigit(digits[i]);
    delay(1000); // Hold each digit for 1s (you can multiplex instead)
  }
}
