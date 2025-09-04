#include <Arduino.h>

const int CLK_PIN = 2;

void setup() {
pinMode(CLK_PIN, OUTPUT);
digitalWrite(CLK_PIN, LOW);
}

void loop() {
digitalWrite(CLK_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(CLK_PIN, LOW);

delay(1000);
}
