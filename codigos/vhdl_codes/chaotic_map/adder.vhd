----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: adder.vdl
-- Description: Fixed point adder
--				Inputs:
--				    X   : First operand
--                  Y   : Second operand
--				Outputs:
--                  A   : Output of adder
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity adder is
	generic( n : integer := 64 );
	port(
        X,Y : in   std_logic_vector(n-1 downto 0);
        A	: out  std_logic_vector(n-1 downto 0) 
	);
end;	

architecture arch of adder is
begin	
	A <= std_logic_vector( signed(X) + signed(Y) );
end;										