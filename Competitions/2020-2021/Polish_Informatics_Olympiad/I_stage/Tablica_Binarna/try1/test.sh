for i in {0..100}
do
    echo $i
    ./main < ../Testy/sporo/in/$i.txt > out.txt
    diff out.txt ../Testy/sporo/out/$i.txt
done