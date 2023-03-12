library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity scm_sigma is
    generic( n : integer := 32 );
    port(
		X	    : in    std_logic_vector(n-1 downto 0);
        M		: out   std_logic_vector(n-1 downto 0)
    );
end;    

architecture arch of scm_sigma is
	signal w1, w4, w5, w20971520 : signed (52 downto 0);
begin   
    w1 <= resize( signed(X), w1'length);
    w4 <= w1(50 downto 0) & "00";
    w5 <= w1 + w4;
    w20971520 <= w5(30 downto 0) & "0000000000000000000000";
    M <=  std_logic_vector( w20971520(52 downto 21) );
end arch;

-- 31 + 22 = 53
-- 52 - x + 1 = 32
-- number_of_bits = left_lim - right_lim + 1

-- El formato es  A(a ,b ) = (10,21) -> 32
--               Ap(ap,bp) = (21,42) -> 64
-- left_lim  = bp + a = 42 + 10 = 52
-- rigth_lim = bp - b = 42 - 21 = 21	