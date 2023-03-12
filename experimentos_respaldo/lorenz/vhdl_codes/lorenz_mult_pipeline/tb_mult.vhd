library ieee;
use ieee.std_logic_1164.all;

entity tb_mult is
	generic( n : integer := 32 );
end entity;

architecture tb of tb_mult is
	signal		RST,CLK       		:	std_logic := '0';
	signal		T1,T2,M1           	:	std_logic_vector(n-1 downto 0);
	signal		R2,M2           	:	std_logic_vector(n-1 downto 0);
begin 
	
	UUT1	: entity work.mult	generic map(n => 32) port map(RST,CLK,T1,T2,M1);
	UUT2	: entity work.mult	generic map(n => 32) port map(RST,CLK,M1,R2,M2);
	RST <= '1', '0' after 10 ns;
	CLK <= not CLK after 10 ns;				-- La mitad del perido que es 20 ns
	
	process
		constant period: time := 20 ns;
	begin
	
		T1 <= "00000001010000000000000000000000";  -- 10.0
		T2 <= "00000000010000000000000000000000";  -- 2.0
		R2 <= "00000000010100000000000000000000";  -- 1.5
		wait for 90 ns;
		
		T1 <= "00000001010000000000000000000000";  -- 10.0
		T2 <= "00000000100000000000000000000000";  -- 4.0
		R2 <= "00000000010100000000000000000000";  -- 1.5
		wait for 90 ns;
		
		T1 <= "00000001010000000000000000000000";  -- 10.0
		T2 <= "00000000110000000000000000000000";  -- 6.0
		R2 <= "00000000010100000000000000000000";  -- 1.5
		wait for 90 ns;
	end process;
	
	-- NOTA: Simular por almenos 1000 ns	   
	-- wait for 10 ns;
end architecture;	  

