#include <Arduino.h>

const int ledPin = 8; // Built-in LED on most Arduino boards

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int16_t num = -28;            // decimal number
  uint16_t rep = (uint16_t)num; // convert to 16-bit 2's complement

  for (int i = 15; i >= 0; i--) {
    int bitVal = (rep >> i) & 1;

    if (bitVal == 1) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }

    delay(700); // ON or OFF duration (readable speed)
    digitalWrite(ledPin, LOW); 
    delay(300); // gap between bits
  }

  delay(2000); // pause before repeating full 16 bits
}
