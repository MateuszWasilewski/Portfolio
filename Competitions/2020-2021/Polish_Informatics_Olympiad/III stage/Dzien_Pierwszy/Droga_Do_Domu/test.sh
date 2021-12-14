z=15
for i in {a..f}
do
    time ./main < OI/dro$z$i.in > out.out
    diff out.out OI/dro$z$i.out
done
