module adder4(a, b, cin, s, cout);

input cin;
input [3:0] a,b;
output cout;
output [3:0] s;

assign {cout, s} = a + b + cin;

endmodule

module test_adder4;

reg cint;
reg [3:0] at, bt;
wire coutt;
wire [3:0] st;

adder4 adder4_inst(at, bt, cint, st, coutt);

initial
	#100 $finish;
initial
begin
	#0 at = 4'b1010; bt = 4'b0101; cint = 1'b0;
	#10 cint = 1'b1;
	#10 at = 4'b1110; bt = 4'b0001;
	#10 cint = 1'b0;
end

endmodule
