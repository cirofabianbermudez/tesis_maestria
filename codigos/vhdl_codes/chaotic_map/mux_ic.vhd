----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: mux_ic.vdl
-- Description: Multilexer to select between initial condition or feedback
--				Inputs:
--                  X0   : Initial condition
--					Xn_1 : feedback
--                  SEL  : Mux selector
--				Outputs:
--                  Xn   : Mux output
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity mux_ic is
    generic( n : integer := 64);
	port(
        X0	: in std_logic_vector(n-1 downto 0);
        Xn_1: in std_logic_vector(n-1 downto 0);	   
        SEL	: in std_logic;
        Xn	: out std_logic_vector(n-1 downto 0)
	);
end;	 		  

architecture arch of mux_ic is
begin
	Xn <= X0 when SEL = '0' else Xn_1;
end;
