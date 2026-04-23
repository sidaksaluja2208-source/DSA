/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];

// DFS function
void dfs(int node, int n) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int countComponents(int n) {
    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, n);
            components++;
        }
    }

    return components;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int u, v;

    // initialize adjacency matrix and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }

    int result = countComponents(n);
    printf("%d\n", result);

    return 0;
}