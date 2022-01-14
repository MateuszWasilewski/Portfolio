#gcc @opcje przyklad1.c napiernaf.c -o main
for i in {1..4}
do
    echo $i
    gcc @opcje-org Testy/przyklad$i.c napiernaf.c -o main
    valgrind --leak-check=full -q --error-exitcode=1 ./main > out.out
    diff out.out Testy/$i.out
done