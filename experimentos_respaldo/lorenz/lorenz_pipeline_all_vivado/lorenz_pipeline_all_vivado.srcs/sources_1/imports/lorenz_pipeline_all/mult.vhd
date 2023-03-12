library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mult is
    generic( n : integer := 32 );
    port(
		RST :	in    std_logic;
		CLK	:	in    std_logic;
		T1,T2	: in    std_logic_vector(n-1 downto 0);
        M1		: out   std_logic_vector(n-1 downto 0)
    );
end;    

architecture arch of mult is
	signal temp : std_logic_vector(2*n-1 downto 0);
	signal Qn, Qp : std_logic_vector(n-1 downto 0);
begin  

    temp <= std_logic_vector( signed(T1)*signed(T2) );
    Qn <= temp(52 downto 21);

	process(RST, CLK)
	begin
		if RST = '1' then
			Qp <= (others => '0');
		elsif rising_edge(CLK) then
			Qp <= Qn;
		end if;
	end process;
	
	M1 <= Qp;
	
end arch;

-- El formato es  A(a ,b ) = (10,21) -> 32
--               Ap(ap,bp) = (21,42) -> 64
-- left_lim  = bp + a = 42 + 10 = 52
-- rigth_lim = bp - b = 42 - 21 = 21	