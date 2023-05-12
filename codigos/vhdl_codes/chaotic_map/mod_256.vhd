----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: mod_256.vdl
-- Description: Does the operation mod 256 
--				Inputs:
--                  Xn  : Input Xn of chaotic map
--					Yn  : Input Yn of chaotic map
--				Outputs:
--                  Sn  : 16 bits, last 8 bits of each input together
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity mod_256 is
	generic( n : integer := 64);
    port(
        Xn  : in  std_logic_vector(n-1 downto 0);
		Yn  : in  std_logic_vector(n-1 downto 0);
        Sn  : out std_logic_vector(15 downto 0)
    );
end;

architecture arch of mod_256 is
begin
	Sn <= Xn(7 downto 0) & Yn(7 downto 0); 
end;
