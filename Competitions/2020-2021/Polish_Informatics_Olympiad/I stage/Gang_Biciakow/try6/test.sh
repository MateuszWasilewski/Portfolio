#g++ -o main main.cpp
z=6
for i in {0..50} 
do
    echo $i 
    time ./main < ../Testy/testy/subtask$z/in/gan$i.in > out.out
    diff out.out ../Testy/testy/subtask$z/out/gan$i.out

done