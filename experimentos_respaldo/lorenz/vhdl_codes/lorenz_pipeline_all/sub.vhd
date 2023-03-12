library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity sub is
	generic( n : integer := 32 );
	port(
		RST :	in    std_logic;
		CLK	:	in    std_logic;
        T1,T2	: in	std_logic_vector(n-1 downto 0);
        S1		: out	std_logic_vector(n-1 downto 0) 
	);
end;	

architecture arch of sub is
	signal Qn, Qp : std_logic_vector(n-1 downto 0);
begin

	Qn <= std_logic_vector( signed(T1) - signed(T2) );

	process(RST, CLK)
	begin
		if RST = '1' then
			Qp <= (others => '0');
		elsif rising_edge(CLK) then
			Qp <= Qn;
		end if;
	end process;
	
	S1 <= Qp;

end arch;	