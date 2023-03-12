library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity scm_rho is
    generic( n : integer := 32 );
    port(
		X	    : in    std_logic_vector(n-1 downto 0);
        M		: out   std_logic_vector(n-1 downto 0)
    );
end;    

architecture arch of scm_rho is
	signal w1, w8, w7, w58720256 : signed (52 downto 0);
begin   
    w1 <= resize( signed(X), w1'length);
    w8 <= w1(49 downto 0) & "000";
    w7 <= w8 - w1;
    w58720256 <= w7(29 downto 0) & "00000000000000000000000";
    M <=  std_logic_vector( w58720256(52 downto 21) );
end arch;


--  31 + 22 = 53
--  52 - x + 1 = 32
-- number_of_bits = left_lim - right_lim + 1

-- El formato es  A(a ,b ) = (10,21) -> 32
--               Ap(ap,bp) = (21,42) -> 64
-- left_lim  = bp + a = 42 + 10 = 52
-- rigth_lim = bp - b = 42 - 21 = 21	