for i in {1..1000}
do
    echo $i
    ./main < in/$i.in > out.out
    diff out.out out/$i.out
done