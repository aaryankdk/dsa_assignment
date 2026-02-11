# Program 5

## Data Structures

### Adjacency Matrix
A 2D array `adj[MAX][MAX]` represents the graph. If there's an edge between vertex i and vertex j, then `adj[i][j] = 1`. Otherwise it's 0.

### Visited Array
Boolean array that tracks which vertices have been visited during traversal.

### Queue
Used for BFS implementation. Has `front` and `rear` pointers to manage the queue operations.

## Functions

### enqueue(int v)
Adds a vertex to the back of the queue.

### dequeue()
Removes and returns a vertex from the front of the queue.

### isempty()
Checks if the queue is empty.

### bfs(int start, int n)
Breadth-first search visits nodes level by level. It starts at the given vertex, visits all its neighbors, then visits all their neighbors, and so on. Uses a queue to keep track of which vertex to visit next.

### dfsutil(int v, int n)
Helper function for DFS. Visits a vertex and then recursively explores each unvisited neighbor.

### dfs(int start, int n)
Depth-first search goes as deep as possible down one path before backtracking. Uses recursion instead of an explicit stack.

## Main Method

Prompts for the number of vertices and edges. Reads each edge as a pair of vertices and updates the adjacency matrix (both directions since it's undirected). Then asks for a starting vertex and runs both BFS and DFS from that point.

## Sample Output

```
enter number of vertices: 5
enter number of edges: 6
enter edges (u v):
0 1
0 2
1 3
1 4
2 4
3 4
enter starting vertex: 0
bfs traversal: 0 1 2 3 4 
dfs traversal: 0 1 3 4 2
```