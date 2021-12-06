echo "Continutul dir. %1"
dir %1
echo "Continutul dir. %3"
dir %3
echo "Continutul dir. %5 inainte de conc."
dir %s
copy %1\%2 + %3\%4 %5\%6
echo "Continutul dir. %5 dupa conc."
dir %5
type %5\%6