#include <stdio.h>

void heapify(int v[], int n, int i){
    int m = i, e = 2*i + 1, d = 2*i + 2, x;

    if(e < n && v[e] > v[m]) m = e;
    if(d < n && v[d] > v[m]) m = d;

    if(m != i){
        x = v[i];
        v[i] = v[m];
        v[m] = x;
        heapify(v, n, m);
    }
}

void heapsort(int v[], int n){
    int i, x;

    for(i = n/2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for(i = n - 1; i > 0; i--){
        x = v[0];
        v[0] = v[i];
        v[i] = x;
        heapify(v, i, 0);
    }
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

        heapsort(v, n);

        for(i = 0; i < n; i++){
            printf("%d", v[i]);
            if(i < n - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
