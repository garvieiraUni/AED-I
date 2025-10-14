#include <stdio.h>

void selecao (int n, int v[]){
    int i, j, min, x;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++)
            if(v[j]<v[min]) min = j;
        x = v[i]; v[i] = v[min]; v[min] = x;
    }
}
 
int main() {
    int nc, n, vetn[3000000], i;
    scanf("%d", &nc);
    while(nc > 0){
        nc--;
        scanf("%d", &n);
        for(i=0;i<n;i++)
            scanf("%d", &vetn[i]);
        selecao(n, vetn);
        for(i=0;i<n;i++)
            printf("%d ",vetn[i]);
        printf("\n");
    }
    return 0;
}
