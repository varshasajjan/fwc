module simple_fsm(
    input wire clk,
    input wire rst,
    input wire switch_in,
    output reg led_out
);

    typedef enum logic [1:0] {
        STATE_OFF = 2'b00,
        STATE_ON  = 2'b01
    } state_t;

    state_t current_state, next_state;

    always @(posedge clk) begin
        if (rst)
            current_state <= STATE_OFF;
        else
            current_state <= next_state;
    end

    always @(*) begin
        case (current_state)
            STATE_OFF: next_state = switch_in ? STATE_ON : STATE_OFF;
            STATE_ON:  next_state = switch_in ? STATE_OFF : STATE_ON;
            default:   next_state = STATE_OFF;
        endcase
    end

    always @(*) begin
        case (current_state)
            STATE_OFF: led_out = 1'b0;
            STATE_ON:  led_out = 1'b1;
            default:   led_out = 1'b0;
        endcase
    end

endmodule
