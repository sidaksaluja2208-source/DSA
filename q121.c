/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/

#include<stdio.h>
#include<stdlib.h>
// Create adjacency matrix
int** createAdjMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
    }
    return matrix;
}
// Add edge to adjacency matrix
void addEdge(int** matrix, int u, int v, int directed) {
    matrix[u][v] = 1;
    if (!directed) {
        matrix[v][u] = 1;
    }
}
// Print adjacency matrix
void printAdjMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n, m, directed;
    scanf("%d %d %d", &n, &m, &directed);
    int** adjMatrix = createAdjMatrix(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adjMatrix, u, v, directed);
    }
    printAdjMatrix(adjMatrix, n);
    // Free memory
    for (int i = 0; i < n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
    return 0;
}
