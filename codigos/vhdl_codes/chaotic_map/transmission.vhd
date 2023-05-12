----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: transmission.vdl
-- Description: Top module for transmission via RS232 protocol               
--				Inputs:
--				    RST : Reset
--                  CLK : Clock
--                  ST  : Clock
--                  D   : Data
--				Outputs:
--                  EOT : End Of Transmission
--                  Tx  : Transmission
--				 Signals:
--					k   : Value to load
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity transmission is
    generic(n: integer := 8; m: integer := 10);
    port(
        RST  : in  std_logic;
        CLK  : in  std_logic;
        ST   : in  std_logic;
        D    : in  std_logic_vector(n-1 downto 0);
		PSEL : in  std_logic;
		K    : in  std_logic_vector(m-1 downto 0);
        EOT  : out std_logic;
		Tx   : out std_logic
	);
end;

architecture arch of transmission is
    signal sel    : std_logic_vector(3 downto 0);
	signal p,z,c  : std_logic;
	signal en     : std_logic;
begin
    mod_mux       : entity work.mux_trans                     port map(sel,D,p,Tx);
	mod_parity    : entity work.parity    generic map(n => 8) port map(D,p);
	mod_freq_div  : entity work.freq_div  generic map(n => m) port map(RST,CLK,'1',K,z);
	mod_fsm_trans : entity work.fsm_trans                     port map(RST,CLK,ST,z,PSEL,EOT,sel);
	-- k <= "10100010101111"; -- 9600   14 bits
	-- k <= "1101100011";     -- 115200 10 bits
end;


