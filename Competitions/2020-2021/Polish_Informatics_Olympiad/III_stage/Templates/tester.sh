#g++ -O3 -static abc.cpp -std=c++17
g++ main.cpp -o main
g++ brut.cpp -o brut
g++ generator.cpp -o generator.exe 

for i in {1..100}
do
    echo $i
    ./generator > testy/in/test$i.in
    ./brut < testy/in/test$i.in > testy/out/test$i.out
    command time -f "%E\n%Mkb" ./main < testy/in/test$i.in > testy/out/odp$i.out
    diff testy/out/test$i.out testy/out/odp$i.out
done