library ieee;
use ieee.std_logic_1164.all;               

entity mux is
    generic( n : integer := 32 ); 
    port(
        W0   : in std_logic_vector(n-1 downto 0);
        Wn_1 : in std_logic_vector(n-1 downto 0);       
        SEL  : in std_logic;
        Wn   : out std_logic_vector(n-1 downto 0)
    );
end;              

architecture arch of mux is
begin
    Wn <= W0 when SEL = '0' else Wn_1;
end arch;