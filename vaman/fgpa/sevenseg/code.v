module gate_with_seven_seg(
    input wire G,
    input wire A,
    input wire B,
    input wire P,
    input wire C,
    output wire [6:0] seg,    // Seven segment pins (a,b,c,d,e,f,g)
    output wire [1:0] digit   // Digit select pins for multiplexing (active low or high as per board)
);

    // Your original logic
    wire and1 = A & G;
    wire and2 = B & G;
    wire xor1 = and1 ^ P;
    wire xor2 = and2 ^ P;
    wire X = xor1 | C;
    wire Y = xor2 | C;

    reg [3:0] display_val;
    reg [1:0] digit_sel;
    reg clkdiv;
    reg [15:0] clkcount = 0;

    // Refresh/multiplexing for 2 digits (if you have dual display)
    always @(posedge clk) begin  // You may need to wire a clock 'clk' from board
        clkcount <= clkcount + 1;
        clkdiv <= clkcount[15];
    end

    always @(*) begin
        if (~clkdiv) begin
            display_val = X;      // Display X on Digit 0
            digit_sel = 2'b10;   // Select digit 0 (edit active high/low as per board)
        end else begin
            display_val = Y;      // Display Y on Digit 1
            digit_sel = 2'b01;   // Select digit 1
        end
    end

    assign digit = digit_sel;

    // Seven segment decoder (0/1 only shown; extend for hex as needed)
    always @(*) begin
        case (display_val)
            4'b0000: seg = 7'b1000000; // "0"
            4'b0001: seg = 7'b1111001; // "1"
            default: seg = 7'b1111111; // blank
        endcase
    end

endmodule
