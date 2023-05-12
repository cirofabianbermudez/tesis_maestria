----------------------------------------------------------------------------------
-- Engineer: Ciro Fabian Bermudez Marquez  
-- Date: 14/06/2022
-- Design Name: fsm_cm.vdl
-- Description: Finite state machine to chaotic map operation.
--				There are 4 states then 2 bits are necessary.
--              Default/Wait, Enable IC, Wait/Change SEL, Enable
--				Inputs:
--				    RST   : Reset
--					CLK   : CLK
--					START : Start FSM
--				Outputs:
--                  EN    : Enable output FF
--					SEL   : Mux selector
--				 Signals:
--					Qp   : FF_output - Present State
--              	Qn   : FF_input - Next State
----------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

entity fsm_cm is
  port(
    RST   : in   std_logic;
    CLK   : in   std_logic;
    START : in   std_logic;
    EN    : out  std_logic;
    SEL   : out  std_logic
  );
end;

architecture arch of fsm_cm is
    signal Qp, Qn  : std_logic_vector(1 downto 0); 
begin
  
  process(Qp,START) 
  begin
    case Qp is
     when "00" => SEL <= '0'; EN <= '0';           -- Default/Wait
        if START = '1' then 
          Qn <= "01";
        else 
          Qn <= Qp;
        end if;
     when "01" => SEL <= '0'; EN <= '1';           -- Enable        
          Qn <= "10";
     when "10" => SEL <= '1'; EN <= '0';           -- Wait/Change SEL
        if START = '1' then 
          Qn <= "11";
        else 
          Qn <= Qp;
        end if;
     when "11" => SEL <= '1'; EN <= '1';            -- Enable
        Qn <= "10";
     when others => SEL <= '0';  EN <= '0';         
        Qn <= "00";
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