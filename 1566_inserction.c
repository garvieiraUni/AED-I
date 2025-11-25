#include <stdio.h>

void insercao(int n, int v[]){
    int i, j, x;
    for(i = 1; i < n; i++){
        x = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > x){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}

int main(){
    int nc, n, i;
    static int vet[3000000];

    scanf("%d", &nc);

    while(nc > 0){
        nc--;

        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &vet[i]);

        insercao(n, vet);

        for(i = 0; i < n; i++)
            printf("%d ", vet[i]);
        printf("\n");
    }

    return 0;
}
