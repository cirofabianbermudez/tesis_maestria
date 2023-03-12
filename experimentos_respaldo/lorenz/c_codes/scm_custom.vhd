library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity scm_custom is
    generic(n : integer := 32);
    port(
        X  :  in  std_logic_vector(n-1 downto 0);
        M  :  out std_logic_vector(n-1 downto 0)
    );
end;

architecture arch of scm_custom is
    signal
    w1,
    w8,
    w7,
    w58720256
    : signed (52 downto 0);
begin

    w1 <= resize(signed(X), w1'length);
    w8 <= w1(49 downto 0) & "000";
    w7 <= w8 - w1;
    w58720256 <= w7(29 downto 0) & "00000000000000000000000";

    M <= std_logic_vector( w58720256(52 downto 21) );

end arch;
