; AVR Assembly for ATmega328P
; Inputs: PD2 (x), PD3 (y), PD4 (z)
; Outputs: PD6 (A), PD7 (B)

.include "m328Pdef.inc"

; Define bit masks
.equ X_BIT = (1<<2)
.equ Y_BIT = (1<<3)
.equ Z_BIT = (1<<4)
.equ LED_A = (1<<6)
.equ LED_B = (1<<7)

.cseg
.org 0x00

rjmp MAIN

MAIN:
    ; Initialize stack pointer
    ldi r16, low(RAMEND)
    out SPL, r16
    ldi r16, high(RAMEND)
    out SPH, r16

    ; Set input pins PD2, PD3, PD4 as inputs (0)
    in r16, DDRD
    andi r16, ~(X_BIT | Y_BIT | Z_BIT) ; clear bits 2,3,4 to input
    out DDRD, r16

    ; Set output pins PD6, PD7 as outputs (1)
    in r16, DDRD
    ori r16, LED_A | LED_B
    out DDRD, r16

LOOP:
    ; Read PORTD inputs
    in r17, PIND

    ; Extract x, y, z bits and move to bit 0 in separate registers
    ; x in r18, y in r19, z in r20 (0 or 1)
    mov r18, r17
    andi r18, X_BIT
    lsr r18
    lsr r18
    lsr r18

    mov r19, r17
    andi r19, Y_BIT
    lsr r19
    lsr r19
    lsr r19
    lsr r19

    mov r20, r17
    andi r20, Z_BIT
    lsr r20
    lsr r20
    lsr r20
    lsr r20

    ; Calculate x + y (OR)
    mov r21, r18
    or r21, r19  ; r21 = x OR y

    ; Calculate y + z (OR)
    mov r22, r19
    or r22, r20  ; r22 = y OR z

    ; Calculate A = (x + y) XOR z
    mov r23, r21
    eor r23, r20

    ; Calculate B = x XOR (y + z)
    mov r24, r18
    eor r24, r22

    ; Prepare PORTD output for LEDs
    in r16, PORTD

    ; Clear LED bits PD6, PD7
    andi r16, ~(LED_A | LED_B)

    ; Set LED_A bit if A=1
    tst r23
    breq SKIP_A
    ori r16, LED_A
SKIP_A:

    ; Set LED_B bit if B=1
    tst r24
    breq SKIP_B
    ori r16, LED_B
SKIP_B:

    out PORTD, r16

    rjmp LOOP
