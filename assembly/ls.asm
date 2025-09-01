.include "m328Pdef.inc"

.org 0x0000
    rjmp RESET

RESET:
    ldi r16, 0x0F       ; lower 4 bits as output for 7447
    out DDRD, r16       

MAIN:
    ; Example inputs: x=1, y=1, z=0
    ldi r17, 1          ; x
    ldi r18, 1          ; y
    ldi r19, 0          ; z

    ; Left expr: (x OR y) XOR z
    mov r20, r17
    or  r20, r18
    eor r20, r19        ; r20 = result (0 or 1)

    ; Send result to 7447 (PORTD0..3)
    andi r20, 0x0F
    out PORTD, r20

    rjmp MAIN
