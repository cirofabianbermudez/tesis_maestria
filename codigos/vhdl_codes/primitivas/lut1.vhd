Library UNISIM;
use UNISIM.vcomponents.all;
-- LUT1: 1-input Look-Up Table with general output
-- 7 Series
-- Xilinx HDL Language Template, version 2021.2
LUT1_inst : LUT1
generic map (
    INIT => "00")
port map (
    O => O, -- LUT general output
    I0 => I0 -- LUT input
);
-- End of LUT1_inst instantiation
