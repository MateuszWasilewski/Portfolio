g++ main.cpp -o main
for i in {0..3}
do
    ./main < in/pla$i.in > out.out
    diff out.out out/pla$i.out
done    