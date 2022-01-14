#include <stdio.h>
#include <stdlib.h>

#include "napiernaf.h"

void pisz(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%+d", a[i]);
    }
    putchar(';');
}

int main(void) {
    int *d, dn;
    iton(10, &d, &dn);
    int *t, tn;
    iton(1000, &t, &tn);
    int *a, an;
    nexp(d, dn, t, tn, &a, &an);
    pisz(d, dn);
    printf(" (%d)\n", ntoi(d, dn));
    pisz(t, tn);
    printf(" (%d)\n", ntoi(t, tn));
    pisz(a, an);
    printf(" (%d)\n", ntoi(a, an));
    free(d);
    free(t);
    free(a);
    return 0;
}