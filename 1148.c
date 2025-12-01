#include <stdio.h>

#define MAXN 500
#define INF 1000000000

int main(){
    int N, E;
    while (scanf("%d %d", &N, &E)==2){
        if(N==0 && E==0) break;

        static int dist[MAXN+1][MAXN+1];
        static int reach[MAXN+1][MAXN+1];

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                dist[i][j] = (i==j ? 0 : INF);
                reach[i][j] = 0;
            }
        }

        for(int i=0;i<E;i++){
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            if(H < dist[X][Y]) dist[X][Y] = H;
            reach[X][Y] = 1;
        }

        // computa transitive closure (reachability)
        for(int k=1;k<=N;k++)
            for(int i=1;i<=N;i++)
                if(reach[i][k])
                    for(int j=1;j<=N;j++)
                        if(reach[k][j]) reach[i][j] = 1;

        // se i e j são mutuamente alcançáveis -> comunicação eletrônica instantânea (0)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                if(i!=j && reach[i][j] && reach[j][i])
                    dist[i][j] = 0;

        // Floyd–Warshall para menores tempos finais
        for(int k=1;k<=N;k++)
            for(int i=1;i<=N;i++)
                if(dist[i][k] < INF)
                    for(int j=1;j<=N;j++)
                        if(dist[k][j] < INF && dist[i][j] > dist[i][k] + dist[k][j])
                            dist[i][j] = dist[i][k] + dist[k][j];

        int K;
        scanf("%d", &K);
        while(K--){
            int O, D;
            scanf("%d %d", &O, &D);
            if(dist[O][D] >= INF) printf("Nao e possivel entregar a carta\n");
            else printf("%d\n", dist[O][D]);
        }
        printf("\n");
    }
    return 0;
}
