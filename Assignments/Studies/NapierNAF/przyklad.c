#include <stdio.h>
#include <stdlib.h>

#include "napiernaf.h"
#include "napiernaf.c"

void pisz(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%+d", a[i]);
    }
    putchar(';');
}

int main(void) {
    int *d, dn;
    iton(2, &d, &dn);
    int *t, tn;
    iton(1, &t, &tn);
    int *a, an;
    nexp(d, dn, t, tn, &a, &an);
    //nadd(d,dn,t,tn,&a,&an);
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