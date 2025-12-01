#include <stdio.h>
#include <stdlib.h>

int V, A;
int adjm[60][60];
int deg[60];
int vis[60];
int odd[60];

int dfs_sub(int u, int p, int *extra){
    vis[u] = 1;
    int cnt = odd[u];
    for(int v=0; v<V; v++){
        if(adjm[u][v] && v != p){
            if(!vis[v]){
                int s = dfs_sub(v, u, extra);
                if(s % 2 == 1) (*extra)++;
                cnt += s;
            }
        }
    }
    return cnt;
}

int main(){
    int T;
    if(scanf("%d", &T) != 1) return 0;
    while(T--){
        int start;
        scanf("%d", &start);
        scanf("%d %d", &V, &A);

        for(int i=0;i<V;i++){
            deg[i] = 0;
            odd[i] = 0;
            vis[i] = 0;
            for(int j=0;j<V;j++) adjm[i][j] = 0;
        }

        int u, v;
        for(int i=0;i<A;i++){
            scanf("%d %d", &u, &v);
            if(u < 0 || u >= V || v < 0 || v >= V) continue;
            if(adjm[u][v] == 0){
                adjm[u][v] = adjm[v][u] = 1;
                deg[u]++; deg[v]++;
            }
        }

        int Aeff = 0;
        for(int i=0;i<V;i++)
            for(int j=i+1;j<V;j++)
                if(adjm[i][j]) Aeff++;

        for(int i=0;i<V;i++) odd[i] = (deg[i] % 2);

        for(int i=0;i<V;i++) vis[i] = 0;
        int extra = 0;
        dfs_sub(start, -1, &extra);

        int ans = Aeff + extra;
        printf("%d\n", ans);
    }
    return 0;
}
