----------------------------------------------
-- JK Flip-Flop with reset 
-- (ESD book Chapter 2.3.1)
-- by Weijun Zhang, 04/2001
--
-- the description of JK Flip-Flop is based 
-- on functional truth table
-- concurrent statement and signal assignment
-- are using in this example 
----------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

----------------------------------------------

entity JK_FF is
port (	data_in1:		in std_logic;
	data_ini1:		in std_logic;
	clock1:		in std_logic;
	data_out:	out std_logic
);
end JK_FF;

-----------------------------------------------

architecture behv of JK_FF is

    -- define the useful signals here

    signal state: std_logic;
    signal input: std_logic_vector(1 downto 0);
    signal clock: std_logic;

begin

    -- combine inputs into vector
    
    input <= data_in1 & data_ini1;

    p: process(clock1) is
        variable n: integer range 0 to 100000000;
        variable clockstate: integer range 0 to 10;
    begin
    
    if clock1'event and clock1 = '1' then
        if n < 100000000 then
            n := n + 1;
        else
            n := 0;
        end if;
        
        if n <= 50000000 then
            clockstate := 1;
        else 
            clockstate := 0;
        end if;
    
    end if;
	
	
	
	if clockstate = 1 then
	   data_out <= '1';
	else
	   data_out <= '0';
	end if;

    end process;
	
    -- concurrent statements
    

end behv;

-------------------------------------------------
