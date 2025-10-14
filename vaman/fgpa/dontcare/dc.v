module dont_care_example(
    input wire A,
    input wire B,
    input wire C,         // Input where 'C' might be don't care in some conditions
    output wire Y
);
    // Define output Y based on A and B; C is don't care for these conditions
    
    // Y = A AND B, regardless of C (don't care)
    assign Y = A & B;

    // Alternatively, if output depends on A, B but C is don't care
    // synthesis tools interpret 'C' absence/irrelevance as don't care.

endmodule
