#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *dados;   // vetor da pilha
    int topo;      // índice do topo
    int tamanho;   // tamanho máximo
} Pilha;

// Inicializa a pilha
void init(Pilha *p, int tamanho) {
    p->dados = (char *)malloc(tamanho * sizeof(char));
    p->topo = 0;
    p->tamanho = tamanho;
}

// Empilha
void push(Pilha *p, char v) {
    if (p->topo < p->tamanho)
        p->dados[p->topo++] = v;
}

// Desempilha, retorna 0 se pilha vazia
int pop(Pilha *p) {
    if (p->topo == 0) return 0;
    p->topo--;
    return 1;
}

// Libera memória da pilha
void libera(Pilha *p) {
    free(p->dados);
}

int main() {
    char exp[1000];

    while (fgets(exp, sizeof(exp), stdin)) {
        int ok = 1;
        Pilha pil;
        init(&pil, strlen(exp));  // tamanho da pilha = tamanho da expressão

        for (int i = 0; exp[i]; i++) {
            if (exp[i] == '(') push(&pil, '(');
            else if (exp[i] == ')')
                if (!pop(&pil)) { ok = 0; break; }
        }

        if (ok && pil.topo == 0) printf("correct\n");
        else printf("incorrect\n");

        libera(&pil);
    }

    return 0;
}
