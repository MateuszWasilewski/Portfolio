#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "napiernaf.h"

#define N 1000

int main(void) {
    int z[N];
    int *d, dn;
    iton(10, &d, &dn);
    int q = N;
    int *a, an;
    nadd(&q, 1, NULL, 0, &a, &an);
    int i = 0;
    while (an > 0) {
        int *x, *r, rn;
        ndivmod(a, an, d, dn, &x, &an, &r, &rn);
        assert(i < N);
        z[i] = ntoi(r, rn);
        ++i;
        free(r);
        free(a);
        a = x;
    }
    while (i > 0) {
        --i;
        printf("%d", z[i]);
    }
    putchar('\n');
    free(a);
    free(d);
    return 0;
}
