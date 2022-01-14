#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned int) time(NULL));
    printf("%ld\n",(long int) rand());
    return 0;
}