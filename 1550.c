#include <stdio.h>

int q[20000], dist[20000];

int rev(int x){
    int r = 0;
    while(x > 0){
        r = r*10 + (x%10);
        x /= 10;
    }
    return r;
}

int bfs(int a, int b){
    int i;
    for(i=0;i<20000;i++) dist[i] = -1;

    int ini = 0, fim = 0;
    q[fim++] = a;
    dist[a] = 0;

    while(ini < fim){
        int u = q[ini++];

        if(u == b) return dist[u];

        /* operação +1 */
        int v = u + 1;
        if(v <= 10000 && dist[v] == -1){
            dist[v] = dist[u] + 1;
            q[fim++] = v;
        }

        /* operação de inverter */
        v = rev(u);
        if(v <= 10000 && dist[v] == -1){
            dist[v] = dist[u] + 1;
            q[fim++] = v;
        }
    }
    return -1;
}

int main(){
    int T, a, b;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &a, &b);
        printf("%d\n", bfs(a, b));
    }
    return 0;
}
