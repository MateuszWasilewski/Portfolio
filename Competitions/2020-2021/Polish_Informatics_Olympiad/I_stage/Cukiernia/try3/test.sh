for i in {0..4}
do
    echo $i
    time ./main < ../../OI/in/cuk$i.in > out.out
    diff out.out ../../OI/out/cuk$i.out

done