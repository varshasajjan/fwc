#include <Arduino.h>

// Segment pins (common anode assumed)
const int segPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Hex digit to segment mapping
// Order: a b c d e f g
// For common anode: 0 = ON, 1 = OFF
byte hexDigits[16][7] = {
  {0,0,0,0,0,0,1}, // 0
  {1,0,0,1,1,1,1}, // 1
  {0,0,1,0,0,1,0}, // 2
  {0,0,0,0,1,1,0}, // 3
  {1,0,0,1,1,0,0}, // 4
  {0,1,0,0,1,0,0}, // 5
  {0,1,0,0,0,0,0}, // 6
  {0,0,0,1,1,1,1}, // 7
  {0,0,0,0,0,0,0}, // 8
  {0,0,0,0,1,0,0}, // 9
  {0,0,0,1,0,0,0}, // A
  {1,1,0,0,0,0,0}, // b
  {0,1,1,0,0,0,1}, // C
  {1,0,0,0,0,1,0}, // d
  {0,1,1,0,0,0,0}, // E
  {0,1,1,1,0,0,0}  // F
};

void displayHexDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], hexDigits[digit][i]);
  }
}

void setup() {
  // Set pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
}

void loop() {
  // -28 in 16-bit 2's complement = 0xFFE4
  int hexValues[4] = {15, 15, 14, 4}; // F, F, E, 4

  for (int i = 0; i < 4; i++) {
    displayHexDigit(hexValues[i]);
    delay(1000); // Show each digit for 1 sec
  }
}
