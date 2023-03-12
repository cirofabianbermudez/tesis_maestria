library ieee;
use ieee.std_logic_1164.all;

entity cu is
  port(
    RST     : in   std_logic;
    CLK     : in   std_logic;
    START   : in   std_logic;
    HAB     : out  std_logic_vector(1 downto 0);
    SEL     : out  std_logic
  );
end;

architecture fsm of cu is
    signal Qp, Qn  : std_logic_vector(3 downto 0); -- porque son 14 estados
begin
  
  process(Qp,START) 
  begin
    case Qp is
        when "0000" => SEL <= '0'; HAB <= "00";         -- espera 1 
            if START = '1' then 
                Qn <= "0001";
            else 
                Qn <= Qp;
            end if;
        when "0001" => SEL <= '0'; HAB <= "11";         -- prop 1
            Qn <= "0010";
        when "0010" => SEL <= '0'; HAB <= "11";         -- prop 2
            Qn <= "0011";
        when "0011" => SEL <= '0'; HAB <= "11";         -- prop 3
            Qn <= "0100";
        when "0100" => SEL <= '0'; HAB <= "11";         -- prop 4
            Qn <= "0101";
        when "0101" => SEL <= '0'; HAB <= "11";         -- prop 5
            Qn <= "0110";
        when "0110" => SEL <= '0'; HAB <= "01";         -- habilita 1        
              Qn <= "0111";
        when "0111" => SEL <= '1'; HAB <= "11";         -- espera 2
            if START = '1' then 
                Qn <= "1000";
            else 
                Qn <= Qp;
            end if;
        when "1000" => SEL <= '1'; HAB <= "11";         -- prop 1
            Qn <= "1001";
        when "1001" => SEL <= '1'; HAB <= "11";         -- prop 2
            Qn <= "1010";
        when "1010" => SEL <= '1'; HAB <= "11";         -- prop 3
            Qn <= "1011";
        when "1011" => SEL <= '1'; HAB <= "11";         -- prop 4
            Qn <= "1100";
        when "1100" => SEL <= '1'; HAB <= "11";         -- prop 5
            Qn <= "1101";
        when "1101" => SEL <= '1'; HAB <= "01";         -- habilita 1        
            Qn <= "0111";
        when others => SEL <= '0';  HAB <= "00";        -- default
            Qn <= "0000";
    end case;
  end process;

  -- Registros para estados
  process(RST, CLK)
	begin
		if RST = '1' then
			Qp <= (others => '0');
		elsif rising_edge(CLK) then
			Qp <= Qn;
		end if;
	end process;

end fsm;
