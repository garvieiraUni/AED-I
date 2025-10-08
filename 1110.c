#include <stdio.h>
#include <stdlib.h>

int main(){
    int pilha[50], descarte[50], k=0, n, i, topo;
    scanf("%d", &n);
    if(n==0) //entrada do número de cartas
        return 0;

    // forma a pilha de cartas, sendo pilha[0] a base
    for(i=n-1; i>=0; i--){
        pilha[i] = n-i;
    }

    while(1){
        if(n == 1)
            break;
        else{
            descarte[k++] = pilha[n-1];//descarta a carta do topo
            n--;
            topo = pilha[n-1]; //salva o novo topo
            for(i=n-1; i>0; i--){
                pilha[i] = pilha[i-1]; //move todas as cartas uma posição para cima
            }
            pilha[0] = topo;//coloca o antigo topo na base
        }
    }
    printf("Discarded cards:");
    for(i=0; i<k; i++){
        if(i==k-1)
            printf(" %d\n", descarte[i]);
        else
            printf(" %d,", descarte[i]);
    }
    printf("Remaining card: %d\n", pilha[0]);
    return 0;
}
