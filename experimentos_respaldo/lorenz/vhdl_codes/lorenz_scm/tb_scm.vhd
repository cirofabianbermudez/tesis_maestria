library ieee;
use ieee.std_logic_1164.all;

entity tb_scm is
	generic( n : integer := 32 );
end entity;

architecture tb of tb_scm is
	signal  CLK		:	std_logic := '0';
	signal	value, check   :  std_logic_vector(n-1 downto 0);
begin 
	CLK <= not CLK after 10 ns;				-- La mitad del perido que es 20 ns
	UUT	: entity work.scm_h generic map(n => 32) port map(value, check);
	process																	
	begin
		
		value <= "00000000001000000000000000000000";
		wait for 50 ns;
		
		value <= "00000000010000000000000000000000";
		wait for 50 ns;
		
		value <= "00000000100000000000000000000000";
		wait for 50 ns;
		
		value <= "00000000001100000000000000000000";
		wait for 50 ns;
	
	end process;
	
	-- NOTA: Simular por almenos 1000 ns	   
	-- wait for 10 ns;
end architecture;	
