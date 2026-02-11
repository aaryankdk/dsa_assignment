#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int adj[MAX][MAX];
bool visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if(front == -1) 
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    int v = queue[front++];
    if(front > rear)
        front = rear = -1;
    return v;
}

bool isempty() {
    return front == -1;
}

void bfs(int start, int n) {
    for(int i = 0; i < n; i++)
        visited[i] = false;
    printf("bfs traversal: ");
    enqueue(start);
    visited[start] = true;
    while(!isempty()) {
        int v = dequeue();
        printf("%d ", v);
        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

void dfsutil(int v, int n) {
    visited[v] = true;
    printf("%d ", v);
    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && !visited[i])
            dfsutil(i, n);
    }
}

void dfs(int start, int n) {
    for(int i = 0; i < n; i++)
        visited[i] = false;
    printf("dfs traversal: ");
    dfsutil(start, n);
    printf("\n");
}

int main() {
    int n, edges;
    printf("enter number of vertices: ");
    scanf("%d", &n);
    // initialize adjacency matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;
    }
    printf("enter number of edges: ");
    scanf("%d", &edges);
    printf("enter edges (u v):\n");
    for(int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }
    int start;
    printf("enter starting vertex: ");
    scanf("%d", &start);
    bfs(start, n);
    dfs(start, n);
    return 0;
}