#include <stdio.h>

void qsort2(int v[], int ini, int fim){
    int i = ini, j = fim, p = v[(ini + fim) / 2], x;
    while(i <= j){
        while(v[i] > p) i++;  // ordem decrescente
        while(v[j] < p) j--;
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
    int t, m, i, k;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &m);

        int v[1000], s[1000];

        for(i = 0; i < m; i++){
            scanf("%d", &v[i]);
            s[i] = v[i];
        }

        qsort2(s, 0, m-1);

        k = 0;
        for(i = 0; i < m; i++)
            if(v[i] == s[i]) k++;

        printf("%d\n", k);
    }

    return 0;
}
