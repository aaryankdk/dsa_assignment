# Program 7

## Data Structures

### Graph Adjacency Matrix
The 2D array `graph[MAX][MAX]` stores edge weights. If there's an edge from vertex i to j, `graph[i][j]` contains the weight. Zero means no edge.

### Distance Array
`dist[MAX]` keeps track of the shortest known distance from the source to each vertex. Starts with infinity for all vertices except the source (which is 0).

### Visited Array
Boolean array marking which vertices have been fully processed.

## Functions

### mindistance(int n)
Finds the unvisited vertex with the smallest tentative distance. This is the next vertex to process.

### dijkstra(int src, int n)
Implements Dijkstra's algorithm. Starts with the source vertex and repeatedly picks the closest unvisited vertex. For each vertex, it checks if going through it provides a shorter path to its neighbors. This is called "relaxation" - if the new path is shorter, the distance gets updated.

### printdistances(int src, int n)
Displays the shortest distance from the source to every vertex. Shows "inf" for unreachable vertices.

## Main Method

Prompts for the number of vertices and edges. Reads each edge with its weight (format: u v weight) and builds the adjacency matrix. Since the graph is undirected, it sets both `graph[u][v]` and `graph[v][u]`. Then asks for the source vertex and runs Dijkstra's algorithm to find shortest paths from that vertex to all others.

## Sample Output

```
enter number of vertices: 5
enter number of edges: 7
enter edges (u v weight):
0 1 4
0 2 1
1 2 2
1 3 5
2 3 8
2 4 10
3 4 2

enter source vertex: 0

vertex	distance from source 0
0	0
1	3
2	1
3	8
4	10
```