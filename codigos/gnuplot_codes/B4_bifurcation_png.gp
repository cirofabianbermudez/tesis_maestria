# Autor: Ciro Fabian Bermudez Marquez
# Date: 16/06/2022
# Description: Plot bifurcation
# Run: gnuplot B5_bifurcation_png.gp

# Terminal epslatex default size 5, 3.5 font "sans,12"  5:3 ratio
reset
unit = 200
#set terminal epslatex size unit*5, unit*3.5
set term png transparent size 5*unit, 3.5*unit
set output "B5_bifurcation.png"                                              
filename = "../c_codes/B4_bifurcation.txt"     

xleft = 2.9; xright = 4; xstep = 0.1
ydown = 0; yup = 1; ystep = 0.2

set xrange [xleft:xright]
set yrange [ydown:yup]

unset xtics
unset ytics

set border 0

graph_style = 102
set style line graph_style linecolor rgb "#000000"\
#                                     linewidth 2 \
#                                     dashtype  1 \
#                                     pointsize 1 \
#                                     pointtype 4 \

unset key
# set size square

# Plot configurations 
plot filename using 1:2 with dots linestyle graph_style