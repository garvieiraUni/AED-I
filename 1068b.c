#include <stdio.h>
#include <stdlib.h>

// Célula da pilha
typedef struct cel {
    char val;
    struct cel *prox;
} cel;

// Empilha um valor
void push(cel **topo, char v) {
    cel *n = malloc(sizeof(cel));
    n->val = v;
    n->prox = *topo;
    *topo = n;
}

// Desempilha e retorna 0 se pilha vazia
int pop(cel **topo) {
    if (!*topo) return 0;
    cel *t = *topo;
    *topo = t->prox;
    free(t);
    return 1;
}

// Libera toda a pilha
void libera(cel **topo) {
    while (*topo) pop(topo);
}

int main() {
    char exp[1000];

    // Lê cada linha da entrada
    while (fgets(exp, sizeof(exp), stdin)) {
        cel *p = NULL;  // topo da pilha
        int ok = 1;     // flag de validade

        // Percorre cada caractere da expressão
        for (int i = 0; exp[i]; i++) {
            if (exp[i] == '(') push(&p, '(');      // abre parêntese = empilha
            else if (exp[i] == ')')                // fecha parêntese = desempilha
                if (!pop(&p)) { ok = 0; break; }  // se pilha vazia = incorreto
        }

        // Verifica se pilha está vazia e expressão é válida
        if (ok && !p) printf("correct\n");
        else printf("incorrect\n");

        libera(&p); // limpa memória da pilha
    }

    return 0;
}

