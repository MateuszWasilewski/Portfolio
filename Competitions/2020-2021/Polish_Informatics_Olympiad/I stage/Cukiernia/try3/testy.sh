for i in {1..1000}
do
    echo $i
        ./main < ../Testy/Podzadanie2/in/cuk$i.in > out.out
        diff -b out.out ../Testy/Podzadanie2/out/cuk$i.out
done