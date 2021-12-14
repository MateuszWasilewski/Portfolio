for i in {1..50}
do
    echo $i
    #./gen_test/main $i > Testy/Moje/nowe/in/$i.in
    #echo generated
    #./try1/main < Testy/Moje/duze/in/$i.in > out.out
    time ./try4/main < Testy/Moje/nowe/in/$i.in > out.out
    diff out.out Testy/Moje/nowe/out/$i.out
    #./try3/main < Testy/Moje/nowe/in/$i.in > Testy/Moje/nowe/out/$i.out
    #diff out.out Testy/Moje/duze/out/$i.out
done