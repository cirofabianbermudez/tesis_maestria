library ieee;
use ieee.std_logic_1164.all;			   

entity mux is
	generic( n : integer := 64);  -- Tamanio de palabra
	port(
        X0	: in std_logic_vector(n-1 downto 0);
        Xn_1: in std_logic_vector(n-1 downto 0);	   
        SEL	: in std_logic;
        Xn	: out std_logic_vector(n-1 downto 0)
	);
end;	 		  

architecture arch of mux is
begin
	Xn <= X0 when SEL = '0' else Xn_1;
end arch;