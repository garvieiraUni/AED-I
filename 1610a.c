#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10005

typedef struct No {
    int v;
    struct No *prox;
} No;

No *adj[MAX];
int estado[MAX];
int N;
int ciclo;

/* Cria novo nó */
No* novo(int v) {
    No *p = (No*)malloc(sizeof(No));
    p->v = v;
    p->prox = NULL;
    return p;
}

/* DFS para detectar ciclo */
void dfs(int u) {
    estado[u] = 1; // visitando

    for (No *p = adj[u]; p != NULL; p = p->prox) {
        int v = p->v;

        if (estado[v] == 1) {
            ciclo = 1;
            return;
        }

        if (estado[v] == 0)
            dfs(v);

        if (ciclo) return;
    }

    estado[u] = 2; // finalizado
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M;
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            adj[i] = NULL;
            estado[i] = 0;
        }

        ciclo = 0;

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);

            No *p = novo(B);
            p->prox = adj[A];
            adj[A] = p;
        }

        for (int i = 1; i <= N && !ciclo; i++) {
            if (estado[i] == 0)
                dfs(i);
        }

        if (ciclo)
            printf("SIM\n");
        else
            printf("NAO\n");

        /* Libera memória */
        for (int i = 1; i <= N; i++) {
            No *p = adj[i];
            while (p) {
                No *tmp = p;
                p = p->prox;
                free(tmp);
            }
        }
    }

    return 0;
}

