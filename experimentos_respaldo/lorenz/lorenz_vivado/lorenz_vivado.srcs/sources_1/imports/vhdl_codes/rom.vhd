library ieee;
use ieee.std_logic_1164.all;

entity rom is
	generic( n : integer := 32 );
	port(
		sigma,beta,rho,h,x0,y0,z0	: out	std_logic_vector(n-1 downto 0)
	);	
end rom;					 

architecture arch of rom is
begin	  	
	sigma <= "00000001010000000000000000000000"; -- 10.00000
	beta  <= "00000000010101010101010101010101"; -- 2.66667
	rho   <= "00000011100000000000000000000000"; -- 28.00000
	h     <= "00000000000000000010100011110101"; -- 0.00500
	x0    <= "00000000001000000000000000000000"; -- 1.00000
	y0    <= "00000000000000000000000000000000"; -- 0.00000
	z0    <= "00000000001000000000000000000000"; -- 1.00000
end arch;