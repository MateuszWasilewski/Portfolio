z=5
for i in {0..100}
do
    echo $i
    ./try1/main < Testy/subtask$z/in/tab$i.in > out.out
    diff out.out Testy/subtask$z/out/tab$i.out
done