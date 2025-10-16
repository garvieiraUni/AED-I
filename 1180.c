#include <stdio.h>

int main() {
    int menor, pos, n, i;
    //pega o tamanho do vetor
    scanf("%d", &n);
    int x[n];
    //pega os valores do vetor
    for(i=0; i<n; i++){
        scanf("%d", &x[i]);
    }
    //percorre o vetor e armazena o menor valor que aparecer em <menor> e sua posição em <pos>.
    for(i=0; i<n; i++){
        if(i==0){
            menor = x[i];
            pos = 0;
        }
        else{
            if(x[i]<menor){
                menor = x[i];
                pos = i;
            }
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);
    return 0;
}
