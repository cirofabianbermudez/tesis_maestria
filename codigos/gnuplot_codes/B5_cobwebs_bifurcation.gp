# Autor: Ciro Bermudez
# Date: 16/06/2022
# Description: Cobwebs for chaotic maps
# Run: gnuplot -c "B5_cobwebs_bifurcation.gp" 3.2

# Terminal pdfcairo default size 5in, 3in font "sans,12"  5:3 ratio
reset
unit = 1.2
set terminal epslatex size unit*5, unit*3.5
set output "B5_cobwebs_bifurcation.tex"
filename = "../c_codes/B5_cobwebs_bifurcation.txt"

xleft = 0; xright = 1; xstep = 0.2
ydown = 0; yup = 1; ystep = 0.2

set xrange [xleft:xright]
set yrange [ydown:yup]

set xtics xleft,xstep,xright 
set ytics ydown,ystep,yup

set border 1+2+4+8

set key top right box
# set key at 6,0.95 Right box

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

# set tics font ",20"
# set key font ",20"
# set title font ",20"

graph_style = 102
set style line graph_style linecolor rgb "#000000"\
                                     linewidth 2 \
#                                     dashtype  1 \
#                                     pointsize 1 \
#                                     pointtype 4 \

unset key
set size square


beta = 3.0
if (ARGC >= 1) {
    beta = ARG1 + 0
}

set samples 1000
f( x ) = beta * (x-x**2)
set label sprintf("A = %3.1f ",beta)  at 0.1,0.9
plot filename using 1:2 with lines linestyle graph_style,\
     x with lines linestyle graph_style,\
     f(x) with lines linestyle graph_style
