g++ gen.cpp -o gen
g++ brut.cpp -o brut
g++ main.cpp -o main

for i in {1..500}
do
    ./gen 100 $i 500 > testy/in/$i.in
    ./main < testy/in/$i.in > testy/out/$i.out
    ./brut < testy/in/$i.in > out.out
    diff out.out testy/out/$i.out
done