#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000003   // Tamanho da hash (primo grande)

// Estrutura para hash linear probing
char *hashTable[MAX];

// Função simples de hash
unsigned long hash(const char *s) {
    unsigned long h = 5381;
    int c;
    while ((c = *s++))
        h = ((h << 5) + h) + c;  // h * 33 + c
    return h % MAX;
}

// Insere string na hash, retorna 1 se nova, 0 se já existia
int insert(const char *s) {
    unsigned long h = hash(s);

    while (hashTable[h] != NULL) {
        if (strcmp(hashTable[h], s) == 0) {
            return 0; // já existe
        }
        h = (h + 1) % MAX;
    }

    hashTable[h] = strdup(s);  // guarda string
    return 1;                  // nova joia
}

int main() {
    char buffer[1000005];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // remover '\n'
        buffer[strcspn(buffer, "\n")] = '\0';

        if (insert(buffer))
            count++;
    }

    printf("%d\n", count);
    return 0;
}
