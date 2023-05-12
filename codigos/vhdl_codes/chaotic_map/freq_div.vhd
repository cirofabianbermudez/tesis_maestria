----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: freq_div.vdl
-- Description: Frequency divider, using a counter that counts from the 
--              value of "K" to zero generates a clock signal slower than CLK
--              "n" must be the number of bits that has "k"
-- 				Use the following equation to calculate "K" value:
--
--              t      : Time
--              f_fpga : FPGA frequency  [50 MHz]
--              k      : Value to load
--
--              t = (1/f_fpga)(K + 1)
--              k = t*f_fpga - 1
--
--				Inputs:
--				    RST : Reset
--                  CLK : Clock
--					EN  : Enable
--					K   : Value to load
--				Outputs:
--                  Z   : Baud rate CLK
--				 Signals:
--					Qp   : FF_output - Present State
--              	Qn   : FF_input - Next State
--					Qmux : Output of firt mux
--					Zp   : Output of comparator
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity freq_div is
    generic(n	: integer := 4);
    port(
        RST :	in	std_logic;
        CLK :	in	std_logic;
        EN  :	in	std_logic;
        K   :	in	std_logic_vector(n-1 downto 0);
        Z   :	out	std_logic
	);
end;

architecture arch of freq_div is
    signal Qp, Qn, Qmux	: std_logic_vector(n-1 downto 0);
	signal Zp			:	std_logic;
begin		
	-- Mux1
	Qmux <=	Qp 	when EN = '0' else std_logic_vector(unsigned(Qp)-1);
	
	-- Mux2
	Qn <= Qmux when Zp = '0' else K;
	
	-- Comparator
	Zp <= '1' when Qp = (Qp'range => '0') else '0';
	
	Z <= Zp;
	process(RST, CLK)
	begin
		if RST = '1' then
			Qp <= (others => '0');
		elsif rising_edge(CLK) then
			Qp <= Qn;	
		end if;
	end process;
end;
