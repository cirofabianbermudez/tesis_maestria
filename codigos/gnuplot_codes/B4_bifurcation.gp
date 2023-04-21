# Autor: Ciro Fabian Bermudez Marquez
# Date: 16/06/2022
# Description: Plot bifurcation
# Run: gnuplot B4_bifurcation.gp

# Terminal epslatex default size 5, 3.5 font "sans,12"  5:3 ratio
reset
unit = 1.2
set terminal epslatex size unit*5, unit*3.5
set output "B4_bifurcation.tex"                                              
filename = "../c_codes/B4_bifurcation.txt"     

xleft = 2.9; xright = 4; xstep = 0.1
ydown = 0; yup = 1; ystep = 0.2

set xrange [xleft:xright]
set yrange [ydown:yup]

set xtics xleft,xstep,xright 
set ytics ydown,ystep,yup

set border 1+2+4+8

set key top right box

set xlabel "$A$"
set ylabel "$x$" rotate by 0 

grid_major = 100
grid_minor = 101

set style line grid_major dashtype 1 linecolor rgb "#E0E0E0"
set style line grid_minor dashtype 3 linecolor rgb "#C7C7C7"
set grid
set mxtics 2; set mytics 2; 
set grid mxtics mytics linestyle grid_major, lines grid_minor
set tics scale 1,0.01

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