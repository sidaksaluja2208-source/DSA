/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array
int n, m;

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int u, v;

    // Input
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // Undirected graph
    }

    // Start DFS from node 1
    dfs(1);

    // Check if all nodes are visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}