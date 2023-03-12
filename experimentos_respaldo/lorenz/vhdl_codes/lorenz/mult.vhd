library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mult is
    generic( n : integer := 32 );
    port(
		T1,T2	: in    std_logic_vector(n-1 downto 0);
        M1		: out   std_logic_vector(n-1 downto 0)
    );
end;    

architecture arch of mult is
	signal temp : std_logic_vector(2*n-1 downto 0);
begin   												  
    temp <= std_logic_vector( signed(T1)*signed(T2) );
    M1 <= temp(52 downto 21);
end arch;

-- El formato es  A(a ,b ) = (10,21) -> 32
--               Ap(ap,bp) = (21,42) -> 64
-- left_lim  = bp + a = 42 + 10 = 52
-- rigth_lim = bp - b = 42 - 21 = 21	