.INCLUDE "m328Pdef.inc"    ; ATmega328P definitions

.org 0x0000
rjmp MAIN

MAIN:
    ldi r16, 0xFF          ; Set PORTD as output
    out DDRD, r16

LOOP:
    ldi r17, 0x55          ; Example pattern
    out PORTD, r17
    rcall DELAY

    ldi r17, 0xAA          ; Another pattern
    out PORTD, r17
    rcall DELAY

    rjmp LOOP

; ----------------------
; Simple Delay routine
; ----------------------
DELAY:
    ldi r18, 0xFF
    ldi r19, 0xFF
L1: dec r19
    brne L1
    dec r18
    brne L1
    ret
