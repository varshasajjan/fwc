; Assume inputs x,y,z in bits of PIND (PD2, PD3, PD4)
; Outputs A,B on PORTB0 and PORTB1 (for example)

.include "m328Pdef.inc"

.equ X_BIT = (1 << 2)
.equ Y_BIT = (1 << 3)
.equ Z_BIT = (1 << 4)
.equ A_BIT = (1 << 0)
.equ B_BIT = (1 << 1)

.cseg
.org 0x00
rjmp MAIN

MAIN:
    ; Initialize stack pointer
    ldi r16, low(RAMEND)
    out SPL, r16
    ldi r16, high(RAMEND)
    out SPH, r16

    ; Set PORTB pins 0 and 1 as output
    in r16, DDRB
    ori r16, A_BIT | B_BIT
    out DDRB, r16

    ; Set PD2, PD3, PD4 as inputs (0)
    in r16, DDRD
    andi r16, ~(X_BIT | Y_BIT | Z_BIT)
    out DDRD, r16

LOOP:
    ; Read inputs from PIND
    in r17, PIND

    ; Extract x,y,z bits to bit 0 of registers
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

    ; Compute x + y (OR)
    mov r21, r18
    or r21, r19

    ; Compute y + z (OR)
    mov r22, r19
    or r22, r20

    ; Compute A = (x + y) XOR z
    mov r23, r21
    eor r23, r20

    ; Compute B = x XOR (y + z)
    mov r24, r18
    eor r24, r22

    ; Write A and B to PORTB0 and PORTB1
    in r25, PORTB
    andi r25, ~(A_BIT | B_BIT)
    
    ; Set bit 0 if A=1
    tst r23
    breq SKIP_A
    ori r25, A_BIT
SKIP_A:

    ; Set bit 1 if B=1
    tst r24
    breq SKIP_B
    ori r25, B_BIT
SKIP_B:

    out PORTB, r25

    rjmp LOOP
