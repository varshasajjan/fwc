#include <Arduino.h>

/*
  Display 2's complement of -28 (11100100) on a single 7-seg
  via 74LS47 (BCD->7seg). The Arduino runs a 3-bit index (0..7),
  computes f = (~Q2 & ~Q0) | (Q0 & ~Q1) and drives 74LS47's A input
  (B,C,D tied LOW). Each bit is shown for 1 second.
  
  Wiring:
    74LS47 A <- PIN_A (drives BCD bit A)
    74LS47 B,C,D -> GND
    74LS47 outputs -> 7-seg segments (through resistors), common anode -> +5V
*/

const uint8_t PIN_A = 5; // Arduino pin to 74LS47 A input
// B,C,D are tied to GND (0)

void setup() {
  pinMode(PIN_A, OUTPUT);
  digitalWrite(PIN_A, LOW);
  Serial.begin(115200);
}

bool compute_f(uint8_t state) {
  // state = 0..7 maps to Q2 Q1 Q0 where Q2 = bit2, Q1 = bit1, Q0 = bit0
  bool Q0 = (state >> 0) & 1;
  bool Q1 = (state >> 1) & 1;
  bool Q2 = (state >> 2) & 1;

  // f = (~Q2 & ~Q0) | (Q0 & ~Q1)
  bool term1 = (!Q2) && (!Q0);
  bool term2 = Q0 && (!Q1);
  return term1 || term2;
}

void set74ls47_A(bool bitVal) {
  // BCD for '1' is 0001 -> A=1, B=0,C=0,D=0
  // BCD for '0' is 0000 -> A=0
  digitalWrite(PIN_A, bitVal ? HIGH : LOW);
}

void loop() {
  for (uint8_t st = 0; st < 8; ++st) {
    bool f = compute_f(st);
    set74ls47_A(f);

    // debug print: show state and bit
    Serial.print("state ");
    Serial.print(st);
    Serial.print(" (");
    Serial.print((st>>2)&1);
    Serial.print((st>>1)&1);
    Serial.print((st>>0)&1);
    Serial.print(") -> f=");
    Serial.println(f ? 1 : 0);

    delay(1000); // show each bit for 1s
  }
  delay(2000); // pause then repeat
}
