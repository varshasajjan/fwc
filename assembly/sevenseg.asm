.include "m328Pdef.inc"

.org 0x0000
    rjmp RESET

RESET:
    ; Init stack
    ldi r16, HIGH(RAMEND)
    out SPH, r16
    ldi r16, LOW(RAMEND)
    out SPL, r16

    ; PORTD output
    ldi r16, 0xFF
    out DDRD, r16

    clr r1            ; keep r1 = 0 always

MAIN:
    ldi ZH, HIGH(digits*2)   ; load table address
    ldi ZL, LOW(digits*2)

    ldi r18, 10   ; loop 10 digits
LOOP:
    lpm r17, Z+   ; read next pattern
    out PORTD, r17
    rcall delay1s
    dec r18
    brne LOOP

    rjmp MAIN

; --- Seven segment lookup table (0-9) ---
; assuming a-g on PD0..PD6
digits:
    .db 0b00111111 ; 0
    .db 0b00000110 ; 1
    .db 0b01011011 ; 2
    .db 0b01001111 ; 3
    .db 0b01100110 ; 4
    .db 0b01101101 ; 5
    .db 0b01111101 ; 6
    .db 0b00000111 ; 7
    .db 0b01111111 ; 8
    .db 0b01101111 ; 9

; --- Simple delay ---
delay1s:
    ldi r20, 100
d1: ldi r21, 200
d2: ldi r22, 200
d3: dec r22
    brne d3
    dec r21
    brne d2
    dec r20
    brne d1
    ret
