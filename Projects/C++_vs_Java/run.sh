#!/bin/bash

for f in tests/*
do 
    echo "Starting programs on file "$f
    echo "Staring C++"
    time ./main_cpp < $f > cpp.out
    echo "Starting Java with JIT"
    time java -cp src_java/ Main < $f > java.out
    echo "Starting Java without JIT"
    time java -Xint -cp src_java/ Main < $f > java.out
done
rm cpp.out java.out