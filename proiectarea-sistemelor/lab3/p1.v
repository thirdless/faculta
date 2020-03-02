module gen_clk;

reg clk1;
reg clk2;
reg clk3;
	
initial
#200 $finish;

inital
begin
	#0 clk1 = 1'b0;
	forever #5 clk1 = ~clk1;
end

intial
begin
	#0 clk2 = 1'b1;
	forever #10 clk2 = ~clk2;
end

initial
begin
	#0 clk3 = 1'b1;
	#7 clk3 = 1'b0;
	forever #20 clk3 = ~clk3;
end

endmodule
