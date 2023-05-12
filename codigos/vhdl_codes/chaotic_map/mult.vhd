----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: mult.vdl
-- Description: Fixed point multiplier using truncation
--              Use the following equations to calculate correct values
--              The format is   A(a ,b ) = (3 ,60)
--                             Ap(ap,bp) = (6 ,120)
--              left_lim  = bp + a = 120 + 3 = 123
--              right_lim = bp - b = 120 - 60 = 60	
--
--				Inputs:
--				    X   : First operand
--                  Y   : Second operand
--				Outputs:
--                  M   : Output of multiplication
--              Signals:
--				   temp : Partial multiplication
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mult is
	generic( n	:	integer := 64);
	port(
		X,Y	: in  std_logic_vector(n-1 downto 0);
		M	: out std_logic_vector(n-1 downto 0)
	);
end;	

architecture arch of mult is
    signal temp : std_logic_vector(2*n-1 downto 0);
begin	
    temp <= std_logic_vector(signed(X)*signed(Y));
	M <= temp(123 downto 60);
end;