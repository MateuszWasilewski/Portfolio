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
    int *a, an;
    iton(99, &a, &an);
    int *b, bn;
    iton(-11, &b, &bn);
    int *c, cn;
    nadd(a, an, b, bn, &c, &cn);
    int *d, dn;
    nsub(a, an, b, bn, &d, &dn);
    int *e, en;
    nmul(c, cn, d, dn, &e, &en);
    pisz(a, an);
    printf(" (%d)\n", ntoi(a, an));
    pisz(b, bn);
    printf(" (%d)\n", ntoi(b, bn));
    pisz(c, cn);
    printf(" (%d)\n", ntoi(c, cn));
    pisz(d, dn);
    printf(" (%d)\n", ntoi(d, dn));
    pisz(e, en);
    printf(" (%d)\n", ntoi(e, en));
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    return 0;
}
