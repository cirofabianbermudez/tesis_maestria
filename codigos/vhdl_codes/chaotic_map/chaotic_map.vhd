----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: chaotic_map.vdl
-- Description: Implementation of Sproot chaotic map
--				Inputs:
--				    RST   : Reset
--					CLK   : CLK
--					START : Start iterations
--				Outputs:
--                  X    : X variable
--					Y    : X variable
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;			   

entity chaotic_map is
	generic( n : integer := 64);
	port(
	    RST   : in  std_logic;
        CLK   : in  std_logic;
        START : in  std_logic;
		X0,Y0 : in  std_logic_vector(n-1 downto 0);
        X,Y   : out std_logic_vector(n-1 downto 0)
	);
end;	 		  

architecture arch of chaotic_map is
    signal xn,yn,xn_retro,yn_retro : std_logic_vector(n-1 downto 0);
    signal sel,en : std_logic;
    signal an1,an2,an3,an4,an5,an6,an7,an8,an9,an10,an11,an12 : std_logic_vector(n-1 downto 0);
	signal m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11 : std_logic_vector(n-1 downto 0); 
	signal a1,a2,a3,a4,a5,a6,a7,a8,a9,a10 : std_logic_vector(n-1 downto 0); 
begin
    -- Mux
	mux_x	  : entity work.mux_ic generic map(n => 64) port map(X0,xn_retro,sel,xn);
	mux_y	  : entity work.mux_ic generic map(n => 64) port map(Y0,yn_retro,sel,yn);
	
	-- ROM	
	mod_rom   : entity work.rom_cm generic map(n => 64) port map(an1,an2,an3,an4,an5,an6,an7,an8,an9,an10,an11,an12);
	
	-- Multipliers
	mult_m1   : entity work.mult   generic map(n => 64) port map(an3,xn,m1);
	mult_m2   : entity work.mult   generic map(n => 64) port map(an6,yn,m2);
	mult_m3   : entity work.mult   generic map(n => 64) port map(an9,xn,m3);
	mult_m4   : entity work.mult   generic map(n => 64) port map(an12,yn,m4);
	mult_m5   : entity work.mult   generic map(n => 64) port map(xn,yn,m5);	
	mult_m6   : entity work.mult   generic map(n => 64) port map(an4,m5,m6);	
	mult_m7   : entity work.mult   generic map(n => 64) port map(m5,an10,m7);   
	mult_m8   : entity work.mult   generic map(n => 64) port map(a1,xn,m8);
	mult_m9   : entity work.mult   generic map(n => 64) port map(a2,yn,m9);
	mult_m10  : entity work.mult   generic map(n => 64) port map(a3,xn,m10);
	mult_m11  : entity work.mult   generic map(n => 64) port map(a4,yn,m11);
	
	-- Adders
	adder_a1  : entity work.adder  generic map(n => 64) port map(m1,an2,a1);
	adder_a2  : entity work.adder  generic map(n => 64) port map(m2,an5,a2);
	adder_a3  : entity work.adder  generic map(n => 64) port map(m3,an8,a3);
	adder_a4  : entity work.adder  generic map(n => 64) port map(m4,an11,a4);
	adder_a5  : entity work.adder  generic map(n => 64) port map(an1,m8,a5);
	adder_a6  : entity work.adder  generic map(n => 64) port map(m9,m6,a6);
	adder_a7  : entity work.adder  generic map(n => 64) port map(an7,m10,a7);
	adder_a8  : entity work.adder  generic map(n => 64) port map(m11,m7,a8);
	adder_a9  : entity work.adder  generic map(n => 64) port map(a5,a6,a9);
	adder_a10 : entity work.adder  generic map(n => 64) port map(a7,a8,a10);
	
	-- Registers
	ff_xn     : entity work.ff_hab generic map(n => 64) port map(RST,CLK,en,a9,xn_retro);
	ff_yn     : entity work.ff_hab generic map(n => 64) port map(RST,CLK,en,a10,yn_retro);
   
	-- Control Unit
	cu_cm     : entity work.fsm_cm                      port map(RST,CLK,START,en,sel);
	
	X <= xn_retro;	
	Y <= yn_retro;	  
	
end;	
