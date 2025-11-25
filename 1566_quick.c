#include <stdio.h>

void qsort2(int v[], int ini, int fim){
    int i = ini, j = fim, p = v[(ini + fim) / 2], x;

    while(i <= j){
        while(v[i] < p) i++;
        while(v[j] > p) j--;

        if(i <= j){
            x = v[i];
            v[i] = v[j];
            v[j] = x;
            i++;
            j--;
        }
    }

    if(ini < j) qsort2(v, ini, j);
    if(i < fim) qsort2(v, i, fim);
}

int main(){
    int nc, n, i;
    static int v[3000000];

    scanf("%d", &nc);

    while(nc > 0){
        nc--;

        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &v[i]);

        qsort2(v, 0, n - 1);

        for(i = 0; i < n; i++){
            printf("%d", v[i]);
            if(i < n - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
