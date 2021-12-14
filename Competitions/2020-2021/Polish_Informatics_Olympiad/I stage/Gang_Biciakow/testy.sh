for i in {3..4}
do
    for z in {0..1000}
    do
        echo $z
        time ./try3/main < Testy/testy/podzadanie$i/in/gan$z.in > out.out
        diff out.out Testy/testy/podzadanie$i/out/gan$z.out
    done
done