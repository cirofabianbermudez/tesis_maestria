# Author: Ciro Fabian Bermudez Marquez
# Date: 
# Desing name: grafica.gnu
# Description: 
# Run: gnuplot grafica.gnu

unset key                                                   # Hide filename			
set term png size 1024,717                                  # transparent size 640,480
# set term png size transparent 1024,717						
set output "grafica6.png"								
filename = "cobwebs.txt"							
set xrange [0:1]
#et yrange [0:1]
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
plot filename using 1:2:3:4 with vectors linecolor -1 linewidth 2 filled 

# Change terminal, replot and stop to view result
# set term wxt size 1024,717
# replot
# pause -1 "Press enter to continue..."

# In gnuplot terminal run the following to see plot configurations
# gnuplot> test
# gnuplot> exit
