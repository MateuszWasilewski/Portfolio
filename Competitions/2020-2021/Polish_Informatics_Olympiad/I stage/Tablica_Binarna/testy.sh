for i in {0..60}
do
    echo $i
    ./try1/main < Testy/malo/in/tabkad$i.in > out.out
    diff out.out Testy/malo/out/tabkad$i.out

done