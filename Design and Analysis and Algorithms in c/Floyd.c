#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V]) {
    int i, j, k;
    
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    printSolution(dist);
}

void printSolution(int dist[][V]) {
    printf("Shortest distance matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix for the graph (enter '99999' for infinity):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (i == j)
                graph[i][j] = 0;
        }
    }

    floydWarshall(graph);
    return 0;
}

