g++ main2.cpp -o main
for i in {a..a}
do
    echo $i
    ./main < testy/oi/zdj1$i.in > out.out
    diff testy/oi/zdj1$i.out out.out

done