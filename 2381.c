#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{
    char nome[1000];
    struct Aluno* next;
} Aluno;

Aluno* criarAluno(char *nome){
    Aluno* n_aluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(n_aluno->nome, nome);
    n_aluno->next = NULL;
    return n_aluno;
}

void inserirAluno(Aluno** fst, Aluno** lst, char* nome){
    Aluno* n_aluno = criarAluno(nome);
    if (*fst == NULL){
        *fst = *lst = n_aluno;
    }
    else {
        (*lst)->next = n_aluno;
        *lst = n_aluno;
    }
}

int cmpAluno(const void* a, const void* b){
    return strcmp(((Aluno*)a)->nome, ((Aluno*)b)->nome);
}

void sort(Aluno* fst){
    if (fst == NULL || fst->next == NULL){
        return;
    }
    int swtch;
    Aluno *i, *j;
    char temp[1000];

    do{
        swtch = 0;
        i = fst;
        while (i != NULL && i->next != NULL){
            j = i->next;
            if (strcmp(i->nome, j->nome) > 0){
                strcpy(temp, i->nome);
                strcpy(i->nome, j->nome);
                strcpy(j->nome, temp);
                swtch = 1;
            }
            i = i->next;
        }
    }
    while (swtch);
}

char* win(Aluno* fst, int K){
    Aluno* temp = fst;
    for (int i = 1; temp != NULL && i < K; i++){
        temp = temp->next;
    }
    if (temp != NULL){
        return temp->nome;
    }
    return NULL;
}

void freelist(Aluno* fst){
    Aluno* atual = fst;
    while (atual != NULL){
        Aluno* aux = atual;
        atual = atual->next;
        free(aux);
    }
}

int main(){
    int N, K;
    scanf("%i %i", &N, &K);
    char nome[1000];

    Aluno* fst = NULL;
    Aluno* lst = NULL;

    getchar();
    for (int i = 0; i < N; i++){
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
        inserirAluno(&fst, &lst, nome);
    }
    sort(fst);
    printf("%s\n", win(fst, K));
    freelist(fst);
    return 0;
}
