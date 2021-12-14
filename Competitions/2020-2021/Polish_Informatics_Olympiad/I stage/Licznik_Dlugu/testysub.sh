z=3
for i in {0..5000}
do
    echo $i 
    ./try1/main < Testy/subtask$z/in/cuk$i.in > out.out
    diff out.out Testy/subtask$z/out/cuk$i.out

done
