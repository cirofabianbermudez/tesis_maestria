# Engineer: Ciro Fabian Bermudez Marquez
# Date: 16/06/2022
# Desing name: graph_map_latex.gnu
# Description: Plot from data file to latex
# Run: gnuplot G1_graph_map_latex.gnu

unset key                                                  # Hide filename
set terminal epslatex size 7.5, 5.25                       # size 5, 3.5 is the default
set output "graph.tex"												
filename = "../c_codes/output_chaotic.txt"							
set xrange [-1:1]
set yrange [-1:1]
set xtic -1,0.2,1
set ytic -1,0.2,1
set size square
set xlabel "$x_n$"
set ylabel "$y_n$"
set grid

# Plot configurations 
plot filename linetype 7 linecolor -1 pointsize 0.12

# Stop to view result
# set term wxt size 1024,717
# replot
# pause -1 "Press enter to continue..."

# In gnuplot terminal run the following to see plot configurations
# gnuplot> test
# gnuplot> exit