library ieee;
use ieee.std_logic_1164.all;

entity ff_hab is
	generic( n : integer := 32 );
	port(
		RST :	in    std_logic;
		CLK	:	in    std_logic; 
		HAB	:	in    std_logic_vector(1 downto 0);
		D	:	in    std_logic_vector(n-1 downto 0);
		Q	:	out   std_logic_vector(n-1 downto 0)
	);	
end;

architecture ff of ff_hab is
	signal Qn, Qp : std_logic_vector(n-1 downto 0);
begin		 

	with HAB select
	Qn <=  	                 (others => '0') when "00",	  -- Reset
										   D when "01",	  -- Pasar
										  Qp when others; -- Mantener
	process(RST, CLK)
	begin
		if RST = '1' then
			Qp <= (others => '0');
		elsif rising_edge(CLK) then
			Qp <= Qn;
		end if;
	end process;
	Q <= Qp;  
	
end ff;