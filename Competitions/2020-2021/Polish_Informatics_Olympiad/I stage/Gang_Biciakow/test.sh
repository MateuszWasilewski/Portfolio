for i in {4..4}
do
    time ./try1/main < Testy/OI/in/gan$i.in > out.out
    # diff out.out Testy/OI/out/gan$i.out
done