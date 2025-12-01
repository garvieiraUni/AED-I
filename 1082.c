#include <stdio.h>

int V, E;
int adj[26][26];
int vis[26];

void dfs(int u, int comp[], int *cn){
    vis[u] = 1;
    comp[(*cn)++] = u;
    for(int v = 0; v < V; v++){
        if(adj[u][v] && !vis[v]) dfs(v, comp, cn);
    }
}

void sort_comp(int comp[], int n){
    for(int i=0;i<n-1;i++){
        int mi = i;
        for(int j=i+1;j<n;j++)
            if(comp[j] < comp[mi]) mi = j;
        if(mi != i){
            int t = comp[i]; comp[i] = comp[mi]; comp[mi] = t;
        }
    }
}

int main(){
    int T;
    if(scanf("%d", &T) != 1) return 0;
    for(int tc = 1; tc <= T; tc++){
        scanf("%d %d", &V, &E);
        for(int i=0;i<26;i++){
            vis[i]=0;
            for(int j=0;j<26;j++) adj[i][j]=0;
        }
        char a,b;
        for(int i=0;i<E;i++){
            scanf(" %c %c", &a, &b);
            int u = a - 'a';
            int v = b - 'a';
            adj[u][v] = adj[v][u] = 1;
        }

        printf("Case #%d:\n", tc);
        int comps = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                int comp[26], cn = 0;
                dfs(i, comp, &cn);
                sort_comp(comp, cn);
                for(int k=0;k<cn;k++){
                    printf("%c,", (char)('a' + comp[k]));
                }
                printf("\n");
                comps++;
            }
        }
        printf("%d connected components\n\n", comps);
    }
    return 0;
}
