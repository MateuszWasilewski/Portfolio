gcc @opcje wielomiany.c -o main
gcc gen.c -o gen
for i in {1..1000}
do
#echo $i
    #./gen $i > testy/$i.in
    #./main < testy/$i.in > testy/$i.out 
    ./main < testy/$i.in > out.out
    diff out.out testy/$i.out
done
