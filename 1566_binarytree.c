#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    int c;
    struct no *l, *r;
} no;

no* ins(no *t, int x) {
    if (t == NULL) {
        t = (no*) malloc(sizeof(no));
        t->v = x;
        t->c = 1;
        t->l = t->r = NULL;
    } else if (x < t->v) {
        t->l = ins(t->l, x);
    } else if (x > t->v) {
        t->r = ins(t->r, x);
    } else {
        t->c++;
    }
    return t;
}

void ord(no *t) {
    no *stk[300];
    int sp = 0;
    int first = 1;

    while (t || sp > 0) {
        while (t) {
            stk[sp++] = t;
            t = t->l;
        }
        t = stk[--sp];

        for (int k = 0; k < t->c; k++) {
            if (!first) printf(" ");
            printf("%d", t->v);
            first = 0;
        }

        t = t->r;
    }
}

void freet(no *t) {
    if (!t) return;
    freet(t->l);
    freet(t->r);
    free(t);
}

int main() {
    int NC, N, x;
    scanf("%d", &NC);

    while (NC--) {
        scanf("%d", &N);

        no *t = NULL;
        for (int i = 0; i < N; i++) {
            scanf("%d", &x);
            t = ins(t, x);
        }

        ord(t);
        printf("\n");

        freet(t);
    }
    return 0;
}
