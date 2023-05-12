----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: mux_system_mod.vdl
-- Description: Multilexer to select between S1 and S2, 8 register
--				Inputs:
--				    SEL : Mux selector
--                  S1  : Input 1
--					S2  : Input 2
--				Outputs:
--                   D  : Mux output
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity mux_system_mod is
	generic( n : integer := 8);
    port(
        SEL : in  std_logic;
        S1  : in  std_logic_vector(n-1 downto 0);
		S2  : in  std_logic_vector(n-1 downto 0);
        D   : out std_logic_vector(7 downto 0)
    );
end;

architecture arch of mux_system_mod is
begin
	D <= S1 when SEL = '0' else S2;
end;
