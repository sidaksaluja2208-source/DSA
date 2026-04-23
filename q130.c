/*Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
bool visited[MAX];

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
bool dfs(int node, int parent) {
    visited[node] = true;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }

        temp = temp->next;
    }
    return false;
}

// Function to detect cycle
bool isCycle(int V) {
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Handle multiple components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4, E = 4;

    // Initialize adjacency list
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Given edges
    int edges[][2] = {{0,1}, {0,2}, {1,2}, {2,3}};

    for (int i = 0; i < E; i++) {
        addEdge(edges[i][0], edges[i][1]);
    }

    if (isCycle(V))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}