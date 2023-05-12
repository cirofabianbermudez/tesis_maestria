----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: fsm_trans.vdl
-- Description: Finite state machine to control RS232 protocol transmission operation.
--				There are 12 states then 4 bits are necessary.
--              Default/Stop, Sync, Start, D0,D1,D2,D3,D4,D5,D6,D7,Parity
--				Inputs:
--				    RST  : Reset
--					CLK  : CLK
--					ST	 : Start transmission
--					Z    : Baud rate CLK
--					PSEL : Parity select
--				Outputs:
--                  EOT  : End of transmission
--					SEL  : Mux selector			
--				 Signals:
--					Qp   : FF_output - Present State
--              	Qn   : FF_input - Next State
----------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity fsm_trans is
    port(
	    RST	 : in  std_logic;
	    CLK  : in  std_logic;
		ST   : in  std_logic;
	    Z    : in  std_logic;
		PSEL : in  std_logic;
	    EOT  : out std_logic;
	    SEL  : out std_logic_vector(3 downto 0)
  );
end;

architecture arch of fsm_trans is
	signal Qp, Qn  : std_logic_vector(3 downto 0);  
begin
  
	process(Qp,ST,Z,PSEL) 
	begin
	    case Qp is
		    when "0000" => EOT <= '1'; SEL <= "0000"; -- Default and Stop bit
			    if ST = '1' then 
				  Qn <= "0001";
				else 
				  Qn <= Qp;
				end if;
		    when "0001" => EOT <= '0'; SEL <= "0000"; -- Sync
				if Z = '1' then 
				  Qn <= "0010";
				else 
				  Qn <= Qp;
				end if;
		    when "0010" => EOT <= '0'; SEL <= "0001"; -- Start bit
				if Z = '1' then 
				  Qn <= "0011";
				else 
				  Qn <= Qp;
				end if;
		    when "0011" => EOT <= '0'; SEL <= "0010"; -- D0
				if Z = '1' then 
				  Qn <= "0100";
				else 
				  Qn <= Qp;
				end if;
		    when "0100" => EOT <= '0'; SEL <= "0011"; -- D1
				if Z = '1' then 
				  Qn <= "0101";
				else 
				  Qn <= Qp;
				end if;
		    when "0101" => EOT <= '0'; SEL <= "0100"; -- D2
				if Z = '1' then 
				  Qn <= "0110";
				else 
				  Qn <= Qp;
				end if;
		    when "0110" => EOT <= '0'; SEL <= "0101"; -- D3
				if Z = '1' then 
				  Qn <= "0111";
				else 
				  Qn <= Qp;
				end if;
		    when "0111" => EOT <= '0'; SEL <= "0110"; -- D4
				if Z = '1' then 
				  Qn <= "1000";
				else 
				  Qn <= Qp;
				end if;
		    when "1000" => EOT <= '0'; SEL <= "0111"; -- D5
				if Z = '1' then 
				  Qn <= "1001";
				else 
				  Qn <= Qp;
				end if;
		    when "1001" => EOT <= '0'; SEL <= "1000"; -- D6
				if Z = '1' then 
				  Qn <= "1010";
				else 
				  Qn <= Qp;
				end if;
		    when "1010" => EOT <= '0'; SEL <= "1001";  -- D7
			    if Z = '1' then
				    if PSEL = '1' then
					    Qn <= "1011";	
					else
						Qn <= "0000";
					end if;
				else 
				  Qn <= Qp;
				end if;
		    when "1011" => EOT <= '0'; SEL <= "1010";  -- Parity
				if Z = '1' then 
				  Qn <= "0000";
				else 
				  Qn <= Qp;
				end if;
		    when others => EOT <= '1'; SEL <= "0000";
				Qn <= "0000";
		end case;
	end process;

	process(RST,CLK)
	begin
        if RST = '1' then
			Qp <= (others => '0');
		elsif rising_edge(CLK) then
			Qp <= Qn;
		end if;
	end process;

end;

