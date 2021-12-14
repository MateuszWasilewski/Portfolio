g++ main.cpp -o main
for i in {1..1}
do
    for z in {a..e}
    do
        ./main < testy/sza$i$z.in > out.out
        diff out.out testy/sza$i$z.out

    done
done
