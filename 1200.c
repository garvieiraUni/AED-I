#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char v;
    struct no *l, *r;
} no;

no* ins(no *t, char x) {
    if (!t) {
        t = malloc(sizeof(no));
        t->v = x;
        t->l = t->r = NULL;
    } else if (x < t->v)
        t->l = ins(t->l, x);
    else if (x > t->v)
        t->r = ins(t->r, x);
    return t;
}

int busca(no *t, char x) {
    if (!t) return 0;
    if (t->v == x) return 1;
    if (x < t->v) return busca(t->l, x);
    return busca(t->r, x);
}

int first;

void inf(no *t) {
    if (!t) return;
    inf(t->l);
    if (!first) printf(" ");
    printf("%c", t->v);
    first = 0;
    inf(t->r);
}

void pre(no *t) {
    if (!t) return;
    if (!first) printf(" ");
    printf("%c", t->v);
    first = 0;
    pre(t->l);
    pre(t->r);
}

void pos(no *t) {
    if (!t) return;
    pos(t->l);
    pos(t->r);
    if (!first) printf(" ");
    printf("%c", t->v);
    first = 0;
}

int main() {
    no *t = NULL;
    char cmd[20], x;

    while (scanf("%s", cmd) != EOF) {

        if (strcmp(cmd, "I") == 0) {
            scanf(" %c", &x);
            t = ins(t, x);
        }

        else if (strcmp(cmd, "P") == 0) {
            scanf(" %c", &x);
            if (busca(t, x))
                printf("%c existe\n", x);
            else
                printf("%c nao existe\n", x);
        }

        else if (strcmp(cmd, "INFIXA") == 0) {
            first = 1;
            inf(t);
            printf("\n");
        }

        else if (strcmp(cmd, "PREFIXA") == 0) {
            first = 1;
            pre(t);
            printf("\n");
        }

        else if (strcmp(cmd, "POSFIXA") == 0) {
            first = 1;
            pos(t);
            printf("\n");
        }
    }

    return 0;
}
