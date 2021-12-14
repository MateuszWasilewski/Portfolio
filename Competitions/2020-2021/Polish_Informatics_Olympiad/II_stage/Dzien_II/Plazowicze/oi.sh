g++ main.cpp -o main
for i in {a..j}
do
    time ./main < testy/pla11$i.in > out.out
    diff out.out testy/pla11$i.out 

done