# Autor: Ciro Fabian Bermudez Marquez
# Date: 16/06/2022
# Description: Plot logistic curve
# Run: gnuplot B6_many_logistic_curve.gp

# Terminal epslatex default size 5, 3.5 font "sans,12"  5:3 ratio
reset
unit = 1.2
set terminal epslatex size unit*5, unit*3.5
set output "B6_many_logistic_curve.tex"                                              
#filename = "../c_codes/B6_many_logistic_curve.txt"     

xleft = 0; xright = 1; xstep = 0.2
ydown = 0; yup = 1; ystep = 0.2

set xrange [xleft:xright]
set yrange [ydown:yup]

set xtics xleft,xstep,xright 
set ytics ydown,ystep,yup

set border 1+2+4+8

set key top right box

set xlabel "$x_{n}$"
set ylabel "$x_{n+1}$" rotate by 0 

grid_major = 100
grid_minor = 101

set style line grid_major dashtype 1 linecolor rgb "#E0E0E0"
set style line grid_minor dashtype 3 linecolor rgb "#C7C7C7"
set grid
set mxtics 4; set mytics 4; 
set grid mxtics mytics linestyle grid_major, lines grid_minor
set tics scale 1,0.01

graph_style = 102
set style line graph_style linecolor rgb "#000000"\
                                     linewidth 2 \
#                                     dashtype  1 \
#                                     pointsize 1 \
#                                     pointtype 4 \

unset key
set size square
set dummy x
set samples 1000 
f(A,x) = A*x*(1-x)
g(x) = x
# Plot configurations 
plot f(0.5, x) with lines linestyle graph_style,\
     f(1, x) with lines linestyle graph_style,\
     f(3, x) with lines linestyle graph_style,\
     g(x) with lines linestyle graph_style
