#include <stdio.h>

static int aux[3000000];

void merge(int v[], int ini, int mid, int fim){
    int i, j, k;
    i = ini;
    j = mid + 1;
    k = ini;

    while(i <= mid && j <= fim){
        if(v[i] <= v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
    }

    while(i <= mid) aux[k++] = v[i++];
    while(j <= fim) aux[k++] = v[j++];

    for(i = ini; i <= fim; i++)
        v[i] = aux[i];
}

void msort(int v[], int ini, int fim){
    int mid;
    if(ini >= fim) return;
    mid = (ini + fim) / 2;
    msort(v, ini, mid);
    msort(v, mid + 1, fim);
    merge(v, ini, mid, fim);
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

        msort(v, 0, n - 1);

        for(i = 0; i < n; i++){
            printf("%d", v[i]);
            if(i < n - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
