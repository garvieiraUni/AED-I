#include <stdio.h>

int main(){
    int n, m, i, x, first = 1;

    scanf("%d", &n);

    int v[50000];
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &m);

    int mark[100001];
    for(i = 0; i <= 100000; i++)
        mark[i] = 0;

    for(i = 0; i < m; i++){
        scanf("%d", &x);
        mark[x] = 1;
    }

    for(i = 0; i < n; i++){
        if(!mark[v[i]]){
            if(!first) printf(" ");
            printf("%d", v[i]);
            first = 0;
        }
    }

    printf("\n");
    return 0;
}
