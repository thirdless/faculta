module addr(a, b, cin, s, cout);
	input a, b, cin;
	output s, cout;
	assign {cout, s} = a + b + cin;
endmodule

module addr4(a4, b4, cin, s4, cout);
	input [7:0] a4, b4;
	input cin;
	output [7:0] s4;
	output cout;
	wire n1, n2, n3;
endmodule

module reg8(di, do, clk);
	input [7:0] di;
	output [7:0] do;
	input clk;
	reg [7:0] do;
	always@(posedge clk)
		do <= di;
endmodule

module reg8res(di, do, clk, res);
	input [7:0] di;
	output [7:0] do;
	input clk, res;
	reg [7:0] do;
	always@(posedge clk)
		if(res)
			do <= 8'b0;
		else
			do <= di;
endmodule

module cnt4(clk, res, do);
	input clk, res;
	output reg [3:0] do;
	always@(posedge clk)
		if(res)
			do <= 4'b0;
		else
			do <= do + 1;
endmodule

module cnt8(clk, res, do);
	input clk, res;
	output reg [7:0] do;
	always@(posedge clk)
		if(res)
			do <= 8'b0;
		else
			do <= do + 1;
endmodule

module mux12(a, b, sel, z);
	input [15:0] a,b;
	input sel;
	output [15:0] z;
	assign z = sel?b:a;
endmodule

module adderN(a, b, sum);
	input [7:0] a,b;
	output [8:0] sum;
	assign sum = a + b;
endmodule

module top(clk, res, di, do);
	wire [7:0] n1, n2, n3;
	reg8res r1(di, do, clk, res);
	cnt8 c1(clk, res, do);
	mux12 w1(n1, n2, sel, n3);
	reg8 r2(di, do, clk);
endmodule

module test;

	input clk;
	input [7:0] di;
	input res;
	input sel;

	initial
	begin
		#0 clk = 1'b0;
		forever #0 clk = ~clk;
	end

endmodule
