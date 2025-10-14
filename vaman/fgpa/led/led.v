module gate_question(
    input wire G,    // Switch input
    input wire A,    // Switch input
    input wire B,    // Switch input
    input wire P,    // Switch input
    input wire C,    // Switch input
    output wire X,   // LED output
    output wire Y    // LED output
);
// Intermediates from the schematic
wire and1_out = A & G;
wire and2_out = B & G;
wire xor1_out = and1_out ^ P;
wire xor2_out = and2_out ^ P;
assign X = xor1_out | C;
assign Y = xor2_out | C;
endmodule
