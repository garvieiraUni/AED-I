#include <stdio.h>
#include <stdlib.h>

typedef struct Aresta
{
    int origem, destino, peso;
} Aresta;

#define TAMANHO_MAXIMO 600
#define MAX_ARESTAS (((TAMANHO_MAXIMO) * (TAMANHO_MAXIMO - 1)) >> 1)

int conjuntoPai[TAMANHO_MAXIMO];
int tamanhoConjunto[TAMANHO_MAXIMO];
Aresta listaArestas[MAX_ARESTAS];

int encontrarRaiz(int);
int algoritmoKruskal(int);
void trocarValores(int *, int *);
int compararArestas(const void *, const void *);

int main()
{
    int quantidadeVertices, quantidadeArestas, opcao;
    int origem, destino, peso;

    scanf("%d %d %d", &quantidadeVertices, &quantidadeArestas, &opcao);

    for (int indice = 0; indice < quantidadeArestas; ++indice)
    {
        scanf("%d %d %d", &listaArestas[indice].origem, &listaArestas[indice].destino, &listaArestas[indice].peso);
    }

    for (int indice = 0; indice <= quantidadeVertices; ++indice)
    {
        conjuntoPai[indice] = indice;
        tamanhoConjunto[indice] = 1;
    }

    qsort(listaArestas, quantidadeArestas, sizeof(Aresta), compararArestas);

    printf("%d\n", algoritmoKruskal(quantidadeArestas));

    return 0;
}

int compararArestas(const void *aresta1, const void *aresta2)
{
    return ((Aresta *)aresta1)->peso - ((Aresta *)aresta2)->peso;
}

void trocarValores(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int encontrarRaiz(int vertice)
{
    if (vertice == conjuntoPai[vertice])
        return vertice;
    else
        return conjuntoPai[vertice] = encontrarRaiz(conjuntoPai[vertice]);
}

int algoritmoKruskal(int totalArestas)
{
    int custoTotal = 0;
    for (int indice = 0; indice < totalArestas; ++indice)
    {
        int raizOrigem = encontrarRaiz(listaArestas[indice].origem);
        int raizDestino = encontrarRaiz(listaArestas[indice].destino);

        if (raizOrigem != raizDestino)
        {
            if (tamanhoConjunto[raizOrigem] > tamanhoConjunto[raizDestino])
                trocarValores(&raizOrigem, &raizDestino);

            conjuntoPai[raizOrigem] = raizDestino;
            tamanhoConjunto[raizDestino] += tamanhoConjunto[raizOrigem];

            custoTotal += listaArestas[indice].peso;
        }
    }

    return custoTotal * 2;
}
