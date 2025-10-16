#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int val;
    struct cel *prox;
} cel;

// Funções de pilha
void push_pilha(cel **topo, int v) {
    cel *n = malloc(sizeof(cel));
    n->val = v;
    n->prox = *topo;
    *topo = n;
}

int pop_pilha(cel **topo) {
    if (!*topo) return -1;
    cel *t = *topo;
    int v = t->val;
    *topo = t->prox;
    free(t);
    return v;
}

// Funções de fila
void push_fila(cel **ini, cel **fim, int v) {
    cel *n = malloc(sizeof(cel));
    n->val = v;
    n->prox = NULL;
    if (!*ini) {
        *ini = n;
        *fim = n;
    } else {
        (*fim)->prox = n;
        *fim = n;
    }
}

int pop_fila(cel **ini, cel **fim) {
    if (!*ini) return -1;
    cel *t = *ini;
    int v = t->val;
    *ini = t->prox;
    if (!*ini) *fim = NULL;
    free(t);
    return v;
}

// Funções de fila de prioridade
void push_pq(cel **ini, int v) {
    cel *n = malloc(sizeof(cel));
    n->val = v;
    n->prox = *ini;
    *ini = n;
}

int pop_pq(cel **ini) {
    if (!*ini) return -1;
    cel *ant = NULL, *at = *ini, *maior = at, *ant_maior = NULL;
    while (at) {
        if (at->val > maior->val) {
            maior = at;
            ant_maior = ant;
        }
        ant = at;
        at = at->prox;
    }
    int v = maior->val;
    if (ant_maior) ant_maior->prox = maior->prox;
    else *ini = maior->prox;
    free(maior);
    return v;
}

// Libera lista
void libera(cel **topo) {
    while (*topo) {
        cel *t = *topo;
        *topo = t->prox;
        free(t);
    }
}

int main() {
    char linha[1000];
    int n;

    while (fgets(linha, sizeof(linha), stdin)) {
        sscanf(linha, "%d", &n);

        // Inicializa as estruturas
        cel *pilha = NULL;
        cel *fila_ini = NULL;
        cel *fila_fim = NULL;
        cel *pq = NULL;

        int is_pilha = 1;
        int is_fila = 1;
        int is_pq = 1;

        for (int i = 0; i < n; i++) {
            int cmd, x;
            fgets(linha, sizeof(linha), stdin);
            sscanf(linha, "%d %d", &cmd, &x);

            if (cmd == 1) {
                push_pilha(&pilha, x);
                push_fila(&fila_ini, &fila_fim, x);
                push_pq(&pq, x);
            } else {
                if (pop_pilha(&pilha) != x) is_pilha = 0;
                if (pop_fila(&fila_ini, &fila_fim) != x) is_fila = 0;
                if (pop_pq(&pq) != x) is_pq = 0;
            }
        }

        int soma = is_pilha + is_fila + is_pq;
        if (soma == 0) printf("impossible\n");
        else if (soma > 1) printf("not sure\n");
        else {
            if (is_pilha) printf("stack\n");
            if (is_fila) printf("queue\n");
            if (is_pq) printf("priority queue\n");
        }

        // Libera memória
        libera(&pilha);
        libera(&fila_ini);
        libera(&pq);
    }

    return 0;
}
