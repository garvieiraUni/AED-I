#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 100

typedef struct Amigo{
    char nome[M];
    struct Amigo* next;
} Amigo;

Amigo* c_amigo(char* nome){
    Amigo* n_amigo = (Amigo*)malloc(sizeof(Amigo));
    strcpy(n_amigo->nome, nome);
    n_amigo->next = NULL;
    return n_amigo;
}

void insert_antes(Amigo** fst, char* nome, char* antes){
    if (*fst == NULL){
        return;
    }

    if (strcmp((*fst)->nome, antes) == 0){
        Amigo* n_amigo = c_amigo(nome);
        n_amigo->next = *fst;
        *fst = n_amigo;
        return;
    }

    Amigo* temp = *fst;
    while (temp->next != NULL && strcmp(temp->next->nome, antes) != 0){
        temp = temp->next;
    }
    if (temp->next != NULL){
        Amigo* n_amigo = c_amigo(nome);
        n_amigo->next = temp->next;
        temp->next = n_amigo;
    }
}

void insert_fim(Amigo** fst, char* nome){
    Amigo* n_amigo = c_amigo(nome);
    if (*fst == NULL){
        *fst = n_amigo;
        return;
    }
    Amigo* temp = *fst;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n_amigo;
}

void printL(Amigo* fst){
    Amigo* temp = fst;
    while (temp != NULL){
        printf("%s", temp->nome);
        if (temp->next != NULL){
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeL(Amigo* fst){
    Amigo* temp;
    while (fst != NULL){
        temp = fst;
        fst = fst->next;
        free(temp);
    }
}

int main(){
    Amigo* list = NULL;
    Amigo* alist = NULL;
    char input[M];
    char amg_indc[M];

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    char* token = strtok(input, " ");
    while (token != NULL){
        insert_fim(&list, token);
        token = strtok(NULL, " ");
    }

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    token = strtok(input, " ");
    while (token != NULL){
        insert_fim(&alist, token);
        token = strtok(NULL, " ");
    }

    fgets(amg_indc, sizeof(amg_indc), stdin);
    amg_indc[strcspn(amg_indc, "\n")] = 0;
    Amigo* temp = alist;
    while (temp != NULL){
        if (strcmp(amg_indc, "nao") == 0){
            insert_fim(&list, temp->nome);
        }
        else {
            insert_antes(&list, temp->nome, amg_indc);
        }
        temp = temp->next;
    }
    printL(list);
    freeL(list);
    freeL(alist);
    return 0;
}
