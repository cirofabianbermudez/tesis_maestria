library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity scm_beta is
    generic( n : integer := 32 );
    port(
		X	    : in    std_logic_vector(n-1 downto 0);
        M		: out   std_logic_vector(n-1 downto 0)
    );
end;    

architecture arch of scm_beta is
	signal w1,w1048576,w1048577,w4096,w1052673,w65536,w1118209,w16,w1118225,w256,w1118481,w4473924,w5592405 : signed (52 downto 0);
begin   
	w1 <= resize( signed(X), w1'length);
	w1048576 <= w1(32 downto 0) & "00000000000000000000";
	w1048577 <= w1 + w1048576;
	w4096 <= w1(40 downto 0) & "000000000000";
	w1052673 <= w1048577 + w4096;
	w65536 <= w1(36 downto 0) & "0000000000000000";
	w1118209 <= w1052673 + w65536;
	w16 <= w1(48 downto 0) & "0000";
	w1118225 <= w1118209 + w16;
	w256 <= w1(44 downto 0) & "00000000";
	w1118481 <= w1118225 + w256;
	w4473924 <= w1118481(50 downto 0) & "00";
	w5592405 <= w1118481 + w4473924;
	M <= std_logic_vector( w5592405(52 downto 21) );
end arch;

-- 31 + 22 = 53
-- 52 - x + 1 = 32
-- number_of_bits = left_lim - right_lim + 1

-- El formato es  A(a ,b ) = (10,21) -> 32
--               Ap(ap,bp) = (21,42) -> 64
-- left_lim  = bp + a = 42 + 10 = 52
-- rigth_lim = bp - b = 42 - 21 = 21	