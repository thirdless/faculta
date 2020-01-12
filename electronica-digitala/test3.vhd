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
port (	clock:		in std_logic;
	J, K:		in std_logic;
	Q:	out std_logic
);
end JK_FF;

-----------------------------------------------

architecture behv of JK_FF is

    -- define the useful signals here

    signal state: std_logic;
    signal state2: std_logic;
    signal input: std_logic_vector(1 downto 0);
    signal final_clockstate: std_logic;

begin

    -- combine inputs into vector	

    p: process(clock)
        variable n : integer range 0 to 1000000000;
        variable clockstate : integer range 0 to 10;
    begin
    if clock = '1' and clock'event then
    state <= J;
    end if;
    if clock = '1' and clock'event then
    state2 <= state;
    end if;
    Q <= state2;
    end process;

end behv;

-------------------------------------------------
