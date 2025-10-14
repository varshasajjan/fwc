module gate_via_7447(
    input wire G,
    input wire A,
    input wire B,
    input wire P,
    input wire C,
    output wire [3:0] bcd_out   // Wires to 7447 inputs: D C B A
);

    wire and1 = A & G;
    wire and2 = B & G;
    wire xor1 = and1 ^ P;
    wire xor2 = and2 ^ P;

    // Your logic for X and Y
    wire X = xor1 | C;
    wire Y = xor2 | C;

    // DISPLAY LOGIC:
    // For 1-digit, show X or Y.
    // For 2 digits, you can multiplex or prioritize.
    // Here: bcd_out shows X and Y as two digits (modify as needed).
    assign bcd_out = {2'b00, Y, X}; // MSB=Y, LSB=X for demo. Can be all combos 0-3

    // If you want to show only X: assign bcd_out = {3'b000, X};
    // If you want to show only Y: assign bcd_out = {3'b000, Y};
    // To show full BCD output, format as needed.

endmodule
