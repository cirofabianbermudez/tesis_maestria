library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity adder is
	generic( n : integer := 32 );
	port(
        T1,T2	: in    std_logic_vector(n-1 downto 0);
        A1		: out   std_logic_vector(n-1 downto 0) 
	);
end;	

architecture arch of adder is
begin	
	
--	process(RST, CLK)
--	begin
--		if RST = '1' then
--			A1 <= (others => '0');
--		elsif rising_edge(CLK) then
--			A1 <= std_logic_vector( signed(T1) + signed(T2) );
--		end if;	
--	end process;
	
	A1 <= std_logic_vector( signed(T1) + signed(T2) );
	
end arch;	



