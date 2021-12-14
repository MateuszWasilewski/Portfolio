for i in {1..40}
do
    echo $i
    time ./try4/main < Testy/Testy/in/gra$i.in > out.out
    diff Testy/Testy/out/gra$i.out out.out
done