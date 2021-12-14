#g++ -o main main.cpp
z=3
for i in {0..20}
do
    echo $i
    time ./main < ../Testy/testy/podzadanie$z/in/gan$i.in > out.out
    #diff out.out ../Testy/testy/podzadanie$z/out/gan$i.out
done