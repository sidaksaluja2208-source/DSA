/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack
int stack[MAX];
int top = -1;

// Graph
int adj[MAX][MAX];
int visited[MAX];

// Push to stack
void push(int node) {
    stack[++top] = node;
}

// DFS function
void dfs(int node, int V) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, V);
        }
    }

    // Push after visiting all neighbors
    push(node);
}

// Topological Sort
void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V);
        }
    }

    printf("Topological Ordering: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int V = 6;

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Example graph (DAG)
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V);

    return 0;
}