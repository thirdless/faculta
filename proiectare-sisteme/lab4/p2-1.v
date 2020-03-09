module reg8res(di,do,clk,res);
    input [7:0] di;
    output[7:0] do;
    input clk,res;
    reg [7:0] do;
    always@(posedge clk)
        if(res)
        do<=8'b0;
        else
        do<=di;
endmodule
module reg16res(di,do,clk,res);
    input [15:0] di;
    output[15:0] do;
    input clk,res;
    reg [15:0] do;
    always@(posedge clk)
        if(res)
        do<=16'b0;
        else
        do<=di;
endmodule
 
module add8(a,b,sum);
    input[7:0] a,b;
    output[8:0] sum;
    assign sum=a+b;
endmodule
 
module top(clk,res,di1,di2,do1,do2);
    input [15:0] di1;
    input [7:0] di2;
    output [7:0] do1;
    output [8:0] do2;
    input clk,res;
    wire [15:0] r1,r2;
    wire [7:0] dot1,dot2;
 
    reg16res i1(di1,r1,clk,res);
    reg16res i2(r1,r2,clk,res);
    reg8res i3(r2[15:8],do1,clk,res);
    reg8res i4(r2[8:0],dot1,clk,res);
    reg8res i5(di2,dot2,clk,res);
    add8 i6(dot1,dot2,do2);
 
endmodule
 
module test;
    reg clk,res;
    reg [15:0]di1;
    reg [7:0]di2;
    wire [7:0]do1;
    wire [8:0]do2;
 
    initial
        #100 $finish;
    initial
    begin
        #0 clk=1'b1;
        #7 clk=1'b0;
        forever #20 clk=~clk;
    end
    initial
    begin
        #0 res=1'b1;
        #10 di2=8'b00110011;di1=16'b0000001100110000;
        #10 res=1'b0; di1=8'b00010111;
    end
endmodule
