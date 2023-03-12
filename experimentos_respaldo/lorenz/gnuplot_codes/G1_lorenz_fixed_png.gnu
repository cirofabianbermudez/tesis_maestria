# Author: Ciro Fabian Bermudez Marquez
# Date: 16/06/2022
# Desing name: G1_lorenz_fixed_png.gnu
# Description: Plot from data file to png
# Run: gnuplot G1_lorenz_fixed_png.gnu

unset key                                                   # Hide filename			
set term png size 1024,717                                  # transparent size 640,480
# set term png size transparent 1024,717						
# set output "lorenz_oscillator_xy.png"
filename = "../c_codes/output_lorenz_fixed.txt"							
# set xrange [-40:60]
# set yrange [-40:60]
# set xtic -1,0.2,1
# set ytic -1,0.2,1
set size square
set xlabel "x_n"
set ylabel "y_n"
set grid 

# Hide all except graph, add trasparent
# set format x ""
# set format y ""
# unset border
# unset xtics
# unset ytics
# set xlabel ""
# set ylabel ""

# Plot configurations 
# set style line 1 linecolor -1 linewidth 1 pointtype 7 pointsize 0.1
set style line 1 linecolor -1

set output "lorenz_fixed_xy.png"
plot filename using 1:2 with lines linestyle 1

set output "lorenz_fixed_xz.png"
plot filename using 1:3 with lines linestyle 1

set output "lorenz_fixed_yz.png"
plot filename using 2:3 with lines linestyle 1

set output "lorenz_fixed_3d.png"
set view 76, 220
splot filename using 1:2:3 with lines linestyle 1

# Change terminal, replot and stop to view result
# set term wxt size 1024,717
# replot
# pause -1 "Press enter to continue..."

# In gnuplot terminal run the following to see plot configurations
# gnuplot> test
# gnuplot> exit
