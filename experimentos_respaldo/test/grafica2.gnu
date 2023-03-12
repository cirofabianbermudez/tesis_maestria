# Author: Ciro Fabian Bermudez Marquez
# Date: 
# Desing name: grafica.gnu
# Description: 
# Run: gnuplot grafica.gnu

unset key                                                   # Hide filename			
set term png size 1024,717    
# set term png size transparent 1024,717	                              # transparent size 640,480					
set output "grafica2.png"								
filename = "slope.txt"	
# set xrange [0:10]
# set yrange [0:2]
set xtic -0,1,10
set ytic 0,0.1,2
set size square
set xlabel "t"
set ylabel "y"
set grid 

plot filename using 1:2:3:4 with vectors linecolor -1 linewidth 2 filled 