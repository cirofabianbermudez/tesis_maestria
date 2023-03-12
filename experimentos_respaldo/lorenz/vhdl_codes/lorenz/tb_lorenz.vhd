library ieee;
use ieee.std_logic_1164.all;

entity tb_lorenz is
	generic( n : integer := 32 );
end entity;

architecture tb of tb_lorenz is
	signal		RST,CLK,START		:	std_logic := '0';
	signal		xn,yn,zn        	:	std_logic_vector(n-1 downto 0);
begin 
	
	UUT	: entity work.lorenz	generic map(n => 32) port map(CLK,RST,START,xn,yn,zn);
	RST <= '1', '0' after 20 ns;
	CLK <= not CLK after 10 ns;				-- La mitad del perido que es 20 ns
	
	
	START <= '1' after 200 ns, '0' after 2000 ns;
	
	-- NOTA: Simular por almenos 1000 ns	   
	-- wait for 10 ns;
end architecture;