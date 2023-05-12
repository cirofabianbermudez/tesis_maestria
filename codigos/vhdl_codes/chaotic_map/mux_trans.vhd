----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: mux_trans.vdl
-- Description: Multilexer to select between all communication bits,
--				In Data (LSB sent first and MSB sent last)
--				The order is as follows:
--				Default:	  1
--				Start bit:	  0
--				Data: 		  D0 D1 D2 D3 D4 D5 D6 D7
--				Parity:		  P
--				Stop bit:	  1
--
--				Inputs:
--				    SEL: Mux selector
--                  D  : Data
--					P  : Parity
--				Outputs:
--                  Tx : Transmission
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity mux_trans is
    port(
        SEL : in  std_logic_vector(3 downto 0);
        D   : in  std_logic_vector(7 downto 0);
        P   : in  std_logic;
        Tx  : out std_logic
    );
end;

architecture arch of mux_trans is
begin
    with SEL select
	    Tx <=    '1'    when "0000",
	             '0'    when "0001",
				 D(0)   when "0010",
				 D(1)   when "0011",
				 D(2)   when "0100",
				 D(3)   when "0101",
				 D(4)   when "0110",
				 D(5)   when "0111",
				 D(6)   when "1000",
				 D(7)   when "1001",
				 P      when "1010",
				 '1'    when others;
end;
