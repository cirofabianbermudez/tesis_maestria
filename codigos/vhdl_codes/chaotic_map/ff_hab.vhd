----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: ff_hab.vdl
-- Description: Flip-Flop with enable
--				Inputs:
--				    RST : Reset
--                  CLK : Clock
--                  EN  : Enable
--                  D   : Data
--				Outputs:
--                  Q   : Flip-Flop output
--              Signals:
--					Qp  : FF_output - Present State
--              	Qn  : FF_input - Next State
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

entity ff_hab is
	generic(n : integer := 64);
	port(
		RST	:	in	std_logic;
		CLK	:	in	std_logic; 
		EN	:	in	std_logic;
		D	:	in	std_logic_vector(n-1 downto 0);
		Q	:	out	std_logic_vector(n-1 downto 0)
	);	
end;

architecture arch of ff_hab is
    signal Qn, Qp : std_logic_vector(n-1 downto 0);
begin
	
    Qn <= Qp when EN = '0' else D;	 
	
	process(RST, CLK)
	begin
		if RST = '1' then
			Qp <= (others => '0');
		elsif rising_edge(CLK) then
			Qp <= Qn;
		end if;
	end process; 
	Q <= Qp;
end;