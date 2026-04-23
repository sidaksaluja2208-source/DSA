/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list
int graph[MAX][MAX];
bool visited[MAX];
int n; // number of vertices

// DFS function to detect cycle
bool hasCycle(int node, int parent) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (hasCycle(i, node))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle detected
            }
        }
    }
    return false;
}

// Function to check cycle in graph
void detectCycle() {
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycle(i, -1)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main() {
    // Example graph
    n = 5;

    // Initialize graph with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    // Add edges (undirected)
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    // Uncomment below to create a cycle
    // graph[4][1] = graph[1][4] = 1;

    detectCycle();

    return 0;
}