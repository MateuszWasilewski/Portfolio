#./try1/main < test.in > out.out
#diff test.out out.out

for i in {1..1000}
do
    echo $i
    ./try1/main < Testy/duze/in/$i.txt > out.out
    diff Testy/duze/out/$i.txt out.out
done
