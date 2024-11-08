set terminal png size 800,600
set output 'courbe_une_personne.png'

set title "Corubes une personne "
set xlabel "Semaines"
set ylabel "Population"
set grid

plot "courbe_une_personne.csv" using 1:2 with lines title 'C', \
     "courbe_une_personne.csv" using 1:3 with lines title 'S', \
     "courbe_une_personne.csv" using 1:4 with lines title 'E', \
     "courbe_une_personne.csv" using 1:5 with lines title 'V'