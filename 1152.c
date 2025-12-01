#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    int u, v;
    int w;
} Edge;

int *parent;
int *rnk;

int findp(int x){
    while(parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unite(int a, int b){
    int pa = findp(a);
    int pb = findp(b);
    if(pa == pb) return;
    if(rnk[pa] < rnk[pb]) parent[pa] = pb;
    else if(rnk[pb] < rnk[pa]) parent[pb] = pa;
    else {
        parent[pb] = pa;
        rnk[pa]++;
    }
}

int cmp_edge(const void *aa, const void *bb){
    const Edge *a = aa;
    const Edge *b = bb;
    if(a->w < b->w) return -1;
    if(a->w > b->w) return 1;
    return 0;
}

int main(){
    int m, n;
    while(scanf("%d %d", &m, &n) == 2){
        if(m == 0 && n == 0) break;

        Edge *edges = (Edge*) malloc(sizeof(Edge) * n);
        if(!edges) return 0;

        ll total = 0;
        for(int i = 0; i < n; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges[i].u = x;
            edges[i].v = y;
            edges[i].w = z;
            total += (ll)z;
        }

        qsort(edges, n, sizeof(Edge), cmp_edge);

        parent = (int*) malloc(sizeof(int) * m);
        rnk = (int*) malloc(sizeof(int) * m);
        if(!parent || !rnk) return 0;
        for(int i = 0; i < m; i++){
            parent[i] = i;
            rnk[i] = 0;
        }

        ll mst = 0;
        int taken = 0;
        for(int i = 0; i < n && taken < m-1; i++){
            int u = edges[i].u;
            int v = edges[i].v;
            int pu = findp(u);
            int pv = findp(v);
            if(pu != pv){
                unite(pu, pv);
                mst += (ll)edges[i].w;
                taken++;
            }
        }

        printf("%lld\n", total - mst);

        free(edges);
        free(parent);
        free(rnk);
    }
    return 0;
}
