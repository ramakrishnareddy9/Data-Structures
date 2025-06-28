set title 'Graph for Two Points'
set xlabel 'x'
set ylabel 'y'
set xrange [0:30]
set yrange [0:30]
plot 'points_data.txt' with linespoints lw 2 lc 'blue' title 'Line between points'
