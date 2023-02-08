Library UNISIM;
use UNISIM.vcomponents.all;
-- OBUFDS: Differential Output Buffer
-- 7 Series
-- Xilinx HDL Language Template, version 2021.2
OBUFDS_inst : OBUFDS
generic map (
    IOSTANDARD => "DEFAULT", -- Specify the output I/O standard
    SLEW => "SLOW") -- Specify the output slew rate
port map (
    O => O, -- Diff_p output (connect directly to top-level port)
    OB => OB, -- Diff_n output (connect directly to top-level port)
    I => I -- Buffer input
);
-- End of OBUFDS_inst instantiation
