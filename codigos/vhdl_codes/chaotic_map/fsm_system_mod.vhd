----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: fsm_system_mod.vdl
-- Description: Finite state machine to control complete system, chaotic map
--              and RS232 transmission protocol.
--				Inputs:
--				    RST   : Reset
--					CLK   : CLK
--					GO	  : Start system
--					EOT   : End Of Transmission
--				Outputs:
--                  START : Start chaotic map
--					ST    : Start transmission			
--					SEL   : Mux selector
--				 Signals:
--					Qp    : FF_output - Present State
--              	Qn    : FF_input - Next State
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity fsm_system_mod is
    port(
	    RST	  : in  std_logic;
	    CLK   : in  std_logic;
		GO    : in  std_logic;
	    EOT   : in  std_logic;
		START : out std_logic;
	    ST    : out std_logic;
	    SEL   : out std_logic
  );
end;

architecture arch of fsm_system_mod is
	signal Qp, Qn  : std_logic_vector(2 downto 0);
	signal temp : std_logic_vector(2 downto 0);
begin
  	
	process(Qp,GO,EOT) 
	begin
	    case Qp is
		    when "000" => temp <= "000"; -- Default / wait
			    if GO = '1' then 
				  Qn <= "001";
				else 
				  Qn <= Qp;
				end if;
		    when "001" => temp <= "100"; -- Iteration of chaotic map
				  Qn <= "010";
		    when "010" => temp <= "010"; -- Activate transmission
				  Qn <= "011";
		    when "011" => temp <= "000"; -- Wait to the end of transmission
			    if EOT = '1' then
				    Qn <= "100";
				else
				    Qn <= Qp;
				end if;
		    when "100" => temp <= "011"; -- Activate transmission changing mux
		        Qn <= "101";
			when "101" => temp <= "001"; -- Wait to the end of transmission
		        if EOT = '1' then
				    Qn <= "000";
				else
				    Qn <= Qp;
				end if;
		    when others => temp <= "000";
				Qn <= "000";
		end case;
	end process;
	
	START <= temp(2);
	ST    <= temp(1);
	SEL   <= temp(0);

	process(RST,CLK)
	begin
        if RST = '1' then
			Qp <= (others => '0');
		elsif rising_edge(CLK) then
			Qp <= Qn;
		end if;
	end process;

end;

