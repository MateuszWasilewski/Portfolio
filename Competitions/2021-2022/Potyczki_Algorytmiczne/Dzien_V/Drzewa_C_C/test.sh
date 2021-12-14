for i in {1..5}
do
echo $i
    ./main < in/dcc$i.in > out.out
    diff -bB out.out out/dcc$i.out
done
