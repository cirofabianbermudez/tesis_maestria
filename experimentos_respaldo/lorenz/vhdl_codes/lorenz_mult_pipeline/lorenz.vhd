library IEEE;
use IEEE.std_logic_1164.all;               	   

entity lorenz is
    generic( n : integer := 32 );
    port(
		RST     : in  std_logic;
        CLK     : in  std_logic;
        START   : in std_logic;
        x_out    : out  std_logic_vector(n-1 downto 0);
        y_out    : out  std_logic_vector(n-1 downto 0);	 
		z_out    : out  std_logic_vector(n-1 downto 0)
    );
end;              

architecture arch of lorenz is
	signal sel : std_logic;
    signal hab : std_logic_vector(1 downto 0);
	signal xn_retro, yn_retro, zn_retro : std_logic_vector(n-1 downto 0);
	signal xn, yn, zn : std_logic_vector(n-1 downto 0);
	signal s1,s2,s3,s4 : std_logic_vector(n-1 downto 0);
	signal a1,a2,a3 : std_logic_vector(n-1 downto 0);
	signal m1,m2,m3,m4,m5,m6,m7 : std_logic_vector(n-1 downto 0);
	signal sigma_rom, beta_rom, rho_rom, h_rom : std_logic_vector(n-1 downto 0);
	signal x0_rom, y0_rom, z0_rom : std_logic_vector(n-1 downto 0);
begin	
	
    -- Control Unit
    cu_mod  : entity work.cu  port map(RST,CLK,START,hab,sel);                                 -- listo
	
	-- Mux
    mux_x   : entity work.mux    generic map(n => 32) port map(x0_rom,xn_retro,sel,xn);        -- listo
	mux_y   : entity work.mux    generic map(n => 32) port map(y0_rom,yn_retro,sel,yn);        -- listo
	mux_z   : entity work.mux    generic map(n => 32) port map(z0_rom,zn_retro,sel,zn);        -- listo

	-- Rom de parametros
	param	: entity work.rom	generic map(n => 32) port map(sigma_rom, beta_rom, rho_rom, h_rom, x0_rom, y0_rom, z0_rom); -- listo
	
	-- Bloque xn
    sub_2 	: entity work.sub    generic map(n => 32) port map(yn,xn,s2);           			   -- listo
    mult_4  : entity work.mult   generic map(n => 32) port map(RST,CLK,s2,sigma_rom,m4);  				   -- listo
		-- Integrador xn	         
	mult_5  : entity work.mult   generic map(n => 32) port map(RST,CLK,m4,h_rom,m5);      				   -- listo 
	add_1	: entity work.adder  generic map(n => 32) port map(m5,xn,a1);         				   -- listo
	reg_1   : entity work.ff_hab generic map(n => 32) port map(RST,CLK,hab,a1,xn_retro);	  	   -- listo
		

	-- Bloque yn
    sub_1 	: entity work.sub    generic map(n => 32) port map(rho_rom,zn,s1);         			   -- listo
	mult_1  : entity work.mult   generic map(n => 32) port map(RST,CLK,s1,xn,m1);       				   -- listo
	sub_3	: entity work.sub    generic map(n => 32) port map(m1,yn,s3);						   -- listo
		-- Integrador yn	        	
	mult_6  : entity work.mult   generic map(n => 32) port map(RST,CLK,s3,h_rom,m6);      				   -- listo
	add_2	: entity work.adder  generic map(n => 32) port map(m6,yn,a2);        				   -- listo
	reg_2   : entity work.ff_hab generic map(n => 32) port map(RST,CLK,hab,a2,yn_retro);	  	   -- listo
		
		
	-- Bloque zn
	mult_2  : entity work.mult   generic map(n => 32) port map(RST,CLK,yn,xn,m2);           			   -- listo
	mult_3  : entity work.mult   generic map(n => 32) port map(RST,CLK,beta_rom,zn,m3);         		   -- listo
	sub_4	: entity work.sub    generic map(n => 32) port map(m2,m3,s4);						   -- listo
		-- Integrador zn	         
	mult_7  : entity work.mult   generic map(n => 32) port map(RST,CLK,s4,h_rom,m7);         			   -- listo
	add_3	: entity work.adder  generic map(n => 32) port map(m7,zn,a3);        	 			   -- listo
	reg_3   : entity work.ff_hab generic map(n => 32) port map(RST,CLK,HAB,a3,zn_retro);   	       -- listo
		
	x_out <= xn_retro;
	y_out <= yn_retro;
	z_out <= zn_retro;

end arch;