#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

int graph[MAX][MAX];
int dist[MAX];
bool visited[MAX];

int mindistance(int n) {
    int min = INF, minindex = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            minindex = i;
        }
    }
    return minindex;
}

void dijkstra(int src, int n) {
    for(int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;
    for(int count = 0; count < n - 1; count++) {
        int u = mindistance(n);
        if(u == -1)
            break;
        visited[u] = true;
        for(int v = 0; v < n; v++) {
            if(!visited[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
}

void printdistances(int src, int n) {
    printf("\nvertex\tdistance from source %d\n", src);
    for(int i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("%d\tinf\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int n, edges, src;
    printf("enter number of vertices: ");
    scanf("%d", &n);
    // initialize graph
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    }
    printf("enter number of edges: ");
    scanf("%d", &edges);
    printf("enter edges (u v weight):\n");
    for(int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }
    printf("enter source vertex: ");
    scanf("%d", &src);
    dijkstra(src, n);
    printdistances(src, n);
    return 0;
}