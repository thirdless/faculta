

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity Source is
    Port (
        A: in std_logic;
        B: in std_logic;
        C: in std_logic;
        clock: in std_logic;
        LEDOUT: out std_logic
    );
end Source;

architecture Behavioral of Source is

    signal state: std_logic;
    signal med_a: std_logic;
    signal med_b: std_logic;
    signal med_c: std_logic;
    signal final_a: std_logic;
    signal final_b: std_logic;
    signal final_c: std_logic;
    
begin

    p: process(clock, A, B, C) is
        variable n: integer range 0 to 1000000000;
        variable clockstate: integer range 0 to 10;
    begin
    
        -- dublu bistabil d pt a
        if clock = '1' and clock'event then
            med_a <= A;
        end if;
        if clock = '1' and clock'event then
            final_a <= med_a;
        end if;
        
        -- dublu bistabil d pt b
        if clock = '1' and clock'event then
            med_b <= B;
        end if;
        if clock = '1' and clock'event then
            final_b <= med_b;
        end if;
        
        -- dublu bistabil d pt c
        if clock = '1' and clock'event then
            med_c <= C;
        end if;
        if clock = '1' and clock'event then
            final_c <= med_c;
        end if;
        
        if clock = '1' and clock'event then
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
            
            if final_a = '0' then
                -- jk
                if final_b = '1' and final_c = '1' then
                    if state = '0' then
                        state <= '1';
                    elsif state = '1' then
                        state <= '0';
                    end if;
                elsif final_b = '1' and final_c = '0' then
                    state <= '1';
                elsif final_b = '0' and final_c = '1' then
                    state <= '0';
                end if;
            
            elsif final_a = '1' then
            
                if final_b = '0' then
                    -- d
                    state <= final_c;
                elsif final_b = '1' then
                    -- t
                    state <= not final_c;
                end if;
            
            end if;
            
        end if;
        
        LEDOUT <= state;
    
    end process;

end Behavioral;
