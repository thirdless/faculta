library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity Proiect_GATE is
    Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : in STD_LOGIC;
           clock : in STD_LOGIC;
           LEDOUT : out STD_LOGIC);
end Proiect_GATE;

architecture Behavioral of Proiect_GATE is
    signal input: std_logic_vector(1 downto 0);
begin


    proc: process(clock)
        variable n : integer range 0 to 1000000000;
        variable clockstate : integer range 0 to 10;
        variable previous: integer range 0 to 10;
    begin
	   
	   input <= B & C;
	   
	   -- rising edge
	   if clock'event and clock = '1' then
	   
	       -- start clock definitions
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
	       -- end clock definitions
	       if clockstate = 1 then
               if A = '0' then
                   -- jk
                   case input is
                       when "11" =>
                           state <= not state;
                       when "10" =>
                           LEDOUT <= '1';
                       when "01" =>
                           LEDOUT <= '0';
                       when others =>
                           null;
                       end case;
               elsif A = '1' then
                   if B = '0' then
                       -- d
                       if C = '1' then
                            LEDOUT <= '1';
                       elsif C = '0' then
                            LEDOUT <= '0';
                       end if;
                   elsif B = '1' then
                       -- t
                       if C = '1' then
                            LEDOUT <= '0';
                       elsif C = '0' then
                            LEDOUT <= '1';
                       end if;
                   end if;
               end if;
           end if;
	   end if;
    end process;

end Behavioral;
