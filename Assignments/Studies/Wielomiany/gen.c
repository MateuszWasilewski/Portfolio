#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPERACJE 10
#define LIMIT 11
#define SPACJE 20
#define MAX 5
#define CHANCE 10
void spacje() {
    int x = rand() % SPACJE;
    while (x > 0) {
        printf(" ");
        x--;
    }
}

int main(int argc, char **argv) {
    //convert(argv[1]);
    srand(time(NULL) ^ atoi(argv[1]));
    int used = 0;
    for(int i = 0; i < OPERACJE; i++) {
        if (rand() % CHANCE || used == 1)
            printf("+");
        else {
            printf("*");
            used = 1;
       }

        int printed = 0;
        for(int z = LIMIT/2 - 1; z >= 0; z--) {
            spacje();
            int x = rand() % (2 * MAX);
            x -= MAX;
            if(x != 0) {
                if(printed == 1) {
                    spacje();
                    if(x < 0)
                        printf("-");
                    else
                        printf("+");
                }
                spacje();
                if(x != 1 || z == 0)
                    printf("%d", abs(x));
                
                if(z > 0) {
                    spacje();
                    printf("x");
                    if(z > 1) {
                        spacje();
                        printf("^");
                        spacje();
                        printf("%d", z);
                    }
                }
                printed = 1;
            }
        }
        if(printed == 0)
            printf("0");
        
        printf("\n");
    }
    printf(".\n");
}
