#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    int u, v;
    int w;
} Edge;

int *parent;
int *rank;

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

    if(rank[pa] < rank[pb]) parent[pa] = pb;
    else if(rank[pb] < rank[pa]) parent[pb] = pa;
    else{
        parent[pb] = pa;
        rank[pa]++;
    }
}

int cmp_edge(const void *a, const void *b){
    const Edge *ea = a;
    const Edge *eb = b;
    return ea->w - eb->w;
}

int main(){
    int M, N;

    while(1){
        if(scanf("%d %d", &M, &N) != 2) return 0;
        if(M == 0 && N == 0) break;

        Edge *edges = (Edge*) malloc(sizeof(Edge) * N);
        parent = (int*) malloc(sizeof(int) * M);
        rank = (int*) malloc(sizeof(int) * M);

        if(!edges || !parent || !rank) return 0;

        for(int i = 0; i < M; i++){
            parent[i] = i;
            rank[i] = 0;
        }

        for(int i = 0; i < N; i++){
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        qsort(edges, N, sizeof(Edge), cmp_edge);

        ll mst = 0;
        int used = 0;

        for(int i = 0; i < N && used < M - 1; i++){
            int pu = findp(edges[i].u);
            int pv = findp(edges[i].v);

            if(pu != pv){
                unite(pu, pv);
                mst += edges[i].w;
                used++;
            }
        }

        printf("%lld\n", mst);

        free(edges);
        free(parent);
        free(rank);
    }

    return 0;
}
