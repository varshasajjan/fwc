module dff_74hc74(
    input wire clk,     // Clock input (connect to FPGA clock or pushbutton)
    input wire d,       // Data input (connect to switch or FPGA signal)
    output reg q        // Output Q (connect to LED)
);

    always @(posedge clk) begin
        q <= d;
    end

endmodule
