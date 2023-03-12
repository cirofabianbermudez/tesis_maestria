# Author: Ciro Fabian Bermudez Marquez
# Date: 
# Desing name: grafica.gnu
# Description: 
# Run: gnuplot grafica.gnu

unset key                                                   # Hide filename			
set term png size 1024,717                                  # transparent size 640,480
# set term png size transparent 1024,717						
set output "grafica4.png"								
filename = "map.txt"							
# set xrange [-1:1]
# set yrange [-1:1]
# set xtic -1,0.2,1
# set ytic -1,0.2,1
set size square
set xlabel "t"
set ylabel "y"
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
plot filename linetype 7 linecolor -1 linewidth 3 with lines

# Change terminal, replot and stop to view result
# set term wxt size 1024,717
# replot
# pause -1 "Press enter to continue..."

# In gnuplot terminal run the following to see plot configurations
# gnuplot> test
# gnuplot> exit
