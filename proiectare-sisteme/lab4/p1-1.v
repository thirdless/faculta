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
 
module cnt8(clk,res,do);
    input clk,res;
    output reg[7:0] do;
    always@(posedge clk)
    if (res)
        do<=8'b0;
    else
        do<=do+1;
endmodule
 
module mux(a,b,sel,z);
    input [7:0] a,b;
    input sel;
    output [7:0] z;
    assign z=sel?b:a;
endmodule
 
module reg8(di,do,clk);
    input [7:0] di;
    output[7:0] do;
    input clk;
    reg [7:0] do;
    always@(posedge clk)
        do<=di;
endmodule
 
module pr(di,do,clk,sel,res);
    input [7:0] di;
    output [7:0] do;
    input clk,sel,res;
    wire [7:0] do1,do2,do3;
   
    reg8res i1(di,do1,clk,res);
    cnt8 i2(clk,res,do2);
    mux i3(do1,do2,sel,do3);
    reg8 i4(do3,do,clk);
   
   
endmodule
 
module test;
    reg [7:0] di;
    wire [7:0] do;
    reg clk,sel,res;
 
    pr p1(di,do,clk,sel,res);
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
        #0 sel=1'b0; res=1'b1;
        #10 di=8'b00110011;
        #10 res=1'b0; di=8'b00010111;
    end
 
endmodule
