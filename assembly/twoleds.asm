; Boolean Identity Checker
; (x + y) ⊕ z  vs  x ⊕ (y + z)
; ATmega328P, Arduino Uno
; Inputs: PD2=x, PD3=y, PD4=z
; Outputs: PB0 = LHS, PB1 = RHS

.include "m328Pdef.inc"

.def temp = r16
.def xreg = r17
.def yreg = r18
.def zreg = r19
.def lhs  = r20
.def rhs  = r21

.org 0x0000
    rjmp RESET

RESET:
    ; ---- Setup I/O ----
    ; PORTD2,3,4 as inputs
    ldi temp, 0x00
    out DDRD, temp

    ; PORTB0,1 as outputs
    ldi temp, 0x03
    out DDRB, temp

MAIN_LOOP:
    ; ---- Read inputs ----
    in temp, PIND
    lsr temp         ; shift to align PD2→bit0
    lsr temp
    andi temp, 0x07  ; mask bits 0..2 only

    mov xreg, temp
    andi xreg, 0x01  ; isolate x
    mov yreg, temp
    lsr yreg
    andi yreg, 0x01  ; isolate y
    mov zreg, temp
    lsr zreg
    lsr zreg
    andi zreg, 0x01  ; isolate z

    ; ---- Compute LHS = (x OR y) XOR z ----
    mov lhs, xreg
    or  lhs, yreg      ; x OR y
    eor lhs, zreg      ; XOR z

    ; ---- Compute RHS = x XOR (y OR z) ----
    mov rhs, yreg
    or  rhs, zreg      ; y OR z
    eor rhs, xreg      ; XOR with x

    ; ---- Write outputs to PORTB ----
    ; PB0 = lhs, PB1 = rhs
    clr temp
    bst lhs,0
    bld temp,0
    bst rhs,0
    bld temp,1

    out PORTB, temp

    rjmp MAIN_LOOP
