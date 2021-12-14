g++ main2.cpp -o main
g++ gen.cpp -o gen
g++ spr.cpp -o spr

for i in {1..100}
do
    echo $i
    ./gen 500000 $i > testy/in/$i.in
    time ./main < testy/in/$i.in > testy/out/$i.out
    ./spr testy/in$i.in < testy/out/$i.out

done