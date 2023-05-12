----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: system_mod.vdl
-- Description: Complete system module with RS232 and chaotic map                
--				Inputs:
--				    RST   : Reset
--                  CLK   : Clock
--                  START : Start system iterations
--				Outputs:
--                  EOT   : End Of Transmission
--                  Tx    : Transmission
--				 Signals:
--					k   : Value to load
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity system_mod is
    port(
        RST   : in  std_logic;
        CLK   : in  std_logic;
        GO    : in  std_logic;
		Tx    : out std_logic
	);
end;

architecture arch of system_mod is
    signal start, st : std_logic;
    signal eot,sel : std_logic;
	signal x0,y0,x,y : std_logic_vector(64-1 downto 0);
	signal k : std_logic_vector(10-1 downto 0);	 
	signal mux_out,s1,s2 : std_logic_vector(7 downto 0);
	signal sn : std_logic_vector(15 downto 0);
	
begin		   
    mod_transmission   : entity work.transmission   generic map(n => 8, m => 10) port map(RST,CLK,st,mux_out,'1',k,eot,Tx);	
	mod_chaotic_map    : entity work.chaotic_map    generic map(n => 64)         port map(RST,CLK,start,x0,y0,x,y);	
	mod_fms_system_mod : entity work.fsm_system_mod                              port map(RST,CLK,GO,eot,start,st,sel);	
	mod_mod_256        : entity work.mod_256        generic map(n => 64)         port map(x,y,sn);
	mod_mux_system_mod : entity work.mux_system_mod generic map(n => 8)		     port map(sel,s1,s2,mux_out);
	s1 <= sn(15 downto 8);
	s2 <= sn( 7 downto 0);
	x0 <= "0000000110011001100110011001100110011001100110011001100110100000"; --  0.10
	y0 <= "0000001100110011001100110011001100110011001100110011001101000000"; --  0.20
	k  <= "1101100011";     -- 115200 10 bits 
end;