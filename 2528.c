#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INF 0x3f3f3f3fU
#define MAX_NODES 1200

typedef unsigned uint;

uint distances[MAX_NODES];
uint adjacency_matrix[MAX_NODES][MAX_NODES];

void dijkstra(int start_node, int total_nodes, uint graph[MAX_NODES][MAX_NODES], uint *dist);

int main(int argc, char **argv)
{
    int start, destination, excluded_node;
    int num_nodes, num_edges, node_a, node_b;

    while (~scanf("%d %d", &num_nodes, &num_edges))
    {
        for (int i = 0; i <= num_nodes; ++i)
            for (int j = 0; j <= num_nodes; ++j)
                adjacency_matrix[i][j] = INF;

        for (int i = 0; i < num_edges; ++i)
            scanf("%d %d", &node_a, &node_b), adjacency_matrix[node_a][node_b] = adjacency_matrix[node_b][node_a] = 1;

        scanf("%d %d %d", &start, &destination, &excluded_node);

        for (int i = 0; i <= num_nodes; ++i)
            adjacency_matrix[excluded_node][i] = adjacency_matrix[i][excluded_node] = INF;

        dijkstra(start, num_nodes, adjacency_matrix, distances);
        
        printf("%d\n", distances[destination]);
    }

    return 0;
}

void dijkstra(int start_node, int total_nodes, uint graph[MAX_NODES][MAX_NODES], uint *dist)
{
    bool visited[total_nodes + 1];
    memset(visited, false, sizeof(visited));

    for (int i = 0 ; i <= total_nodes; ++i)
        dist[i] = INF;

    dist[start_node] = 0;

    for (int i = 0; i <= total_nodes; ++i)
    {
        int min_node = -1;
        for (int j = 0; j <= total_nodes; ++j)
            if (!visited[j] && (min_node == -1 || dist[j] < dist[min_node]))
                min_node = j;

        if (dist[min_node] == INF)
            break;

        visited[min_node] = true;
        for (int j = 0; j <= total_nodes; ++j)
            if (dist[min_node] + graph[min_node][j] < dist[j])
                dist[j] = graph[min_node][j] + dist[min_node];
    }
}
