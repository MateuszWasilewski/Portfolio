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
    int a[] = {-1, 77232917};
    int an = sizeof a / sizeof *a;
    int b[] = {-1, 74207281};
    int bn = sizeof b / sizeof *b;
    int *c, cn;
    iton(-127, &c, &cn);
    int *d, dn;
    nadd(a, an, b, bn, &d, &dn);
    int *e, en;
    nsub(a, an, c, cn, &e, &en);
    int *f, fn;
    nmul(b, bn, c, cn, &f, &fn);
    pisz(a, an);
    putchar('\n');
    pisz(b, bn);
    putchar('\n');
    pisz(c, cn);
    putchar('\n');
    pisz(d, dn);
    putchar('\n');
    pisz(e, en);
    putchar('\n');
    pisz(f, fn);
    putchar('\n');
    free(c);
    free(d);
    free(e);
    free(f);
    return 0;
}
