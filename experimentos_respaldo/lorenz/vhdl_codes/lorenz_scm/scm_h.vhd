library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity scm_h is
    generic( n : integer := 32 );
    port(
		X	    : in    std_logic_vector(n-1 downto 0);
        M		: out   std_logic_vector(n-1 downto 0)
    );
end;    

architecture arch of scm_h is
	signal w1,w2048,w2049,w256,w2305,w16,w2289,w8196,w10485 : signed (52 downto 0);
begin   
	w1 <= resize( signed(X), w1'length);
	w2048 <= w1(41 downto 0) & "00000000000";
	w2049 <= w1 + w2048;
	w256 <= w1(44 downto 0) & "00000000";
	w2305 <= w2049 + w256;
	w16 <= w1(48 downto 0) & "0000";
	w2289 <= w2305 - w16;
	w8196 <= w2049(50 downto 0) & "00";
	w10485 <= w2289 + w8196;
	M  <= std_logic_vector( w10485(52 downto 21) );
end arch;

-- 31 + 22 = 53
-- 52 - x + 1 = 32
-- number_of_bits = left_lim - right_lim + 1

-- El formato es  A(a ,b ) = (10,21) -> 32
--               Ap(ap,bp) = (21,42) -> 64
-- left_lim  = bp + a = 42 + 10 = 52
-- rigth_lim = bp - b = 42 - 21 = 21	