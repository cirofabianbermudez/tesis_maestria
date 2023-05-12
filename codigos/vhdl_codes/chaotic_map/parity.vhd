----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: parity.vdl
-- Description: Even parity of "n" bits std_logic_vector
--				0 if the number of ones is even
--				1 if the number of ones is odd (not even)
--
--				Inputs:
--				    D : Data
--				Output:
--					P : Parity
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity parity is
    generic(n : integer := 8);
    port(
        D : in  std_logic_vector(n-1 downto 0);
        P : out std_logic
	);	
end;		

architecture arch of parity is
    signal temp : std_logic_vector(n-1 downto 0);
begin	
    temp(0) <= D(0);
    gen: for i in 1 to n-1 generate
        temp(i) <= temp(i-1) xor D(i);
    end generate; 
    P <= temp(n-1); 
end;
