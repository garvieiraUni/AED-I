#include <stdio.h>
#include <stdlib.h>

#define MAXC 10000
#define MAXV 50000
#define MAXE (MAXV*2)

/* valor bem grande para representar "infinito" */
#define INFLL 9000000000000000000LL

int head[2*MAXC + 5], to[MAXE*2 + 5], w[MAXE*2 + 5], nxt[MAXE*2 + 5];
int edges;

void addEdge(int u, int v, int c){
    to[edges] = v;
    w[edges] = c;
    nxt[edges] = head[u];
    head[u] = edges++;
}

/* distâncias e visitados */
long long distArr[2*MAXC + 5];
int used[2*MAXC + 5];

/* heap simples */
long long heapD[4*MAXV + 10];
int heapN[4*MAXV + 10];
int hsz = 0;

void heapPush(long long d, int u){
    int i = ++hsz;
    heapD[i] = d;
    heapN[i] = u;

    while(i > 1){
        int p = i >> 1;
        if(heapD[p] <= heapD[i]) break;

        long long td = heapD[p]; 
        int tu = heapN[p];

        heapD[p] = heapD[i];
        heapN[p] = heapN[i];

        heapD[i] = td;
        heapN[i] = tu;

        i = p;
    }
}

void heapPop(long long *d, int *u){
    if(hsz == 0){
        *d = -1;
        *u = -1;
        return;
    }

    *d = heapD[1];
    *u = heapN[1];

    heapD[1] = heapD[hsz];
    heapN[1] = heapN[hsz];
    hsz--;

    int i = 1;
    while(1){
        int l = i<<1, r = l|1, best = i;

        if(l <= hsz && heapD[l] < heapD[best]) best = l;
        if(r <= hsz && heapD[r] < heapD[best]) best = r;
        if(best == i) break;

        long long td = heapD[i];
        int tu = heapN[i];

        heapD[i] = heapD[best];
        heapN[i] = heapN[best];

        heapD[best] = td;
        heapN[best] = tu;

        i = best;
    }
}

int main(){
    int C, V;

    while(scanf("%d %d", &C, &V) == 2){

        int Nstates = 2*C;
        edges = 0;
        for(int i=0; i<Nstates; i++) head[i] = -1;

        for(int i=0; i<V; i++){
            int c1, c2, g;
            scanf("%d %d %d", &c1, &c2, &g);
            c1--; 
            c2--;

            /* alterna paridade (0->1 e 1->0) */
            addEdge(c1*2 + 0, c2*2 + 1, g);
            addEdge(c1*2 + 1, c2*2 + 0, g);
            addEdge(c2*2 + 0, c1*2 + 1, g);
            addEdge(c2*2 + 1, c1*2 + 0, g);
        }

        for(int i=0; i<Nstates; i++){
            distArr[i] = INFLL;
            used[i] = 0;
        }

        int start = 0;           /* cidade 1, paridade 0 */
        int goal  = (C-1)*2 + 0; /* cidade C, paridade 0 */

        hsz = 0;
        distArr[start] = 0;
        heapPush(0, start);

        while(hsz > 0){
            long long d;
            int u;
            heapPop(&d, &u);

            if(u == -1) break;
            if(d != distArr[u]) continue;
            if(used[u]) continue;
            used[u] = 1;

            if(u == goal) break;

            for(int e = head[u]; e != -1; e = nxt[e]){
                int v = to[e];
                long long nd = d + w[e];
                if(nd < distArr[v]){
                    distArr[v] = nd;
                    heapPush(nd, v);
                }
            }
        }

        if(distArr[goal] >= INFLL) printf("-1\n");
        else printf("%lld\n", distArr[goal]);
    }

    return 0;
}
