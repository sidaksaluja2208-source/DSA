/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int V;
    Node* adj[MAX];
} Graph;

// Create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge (directed)
void addEdge(Graph* graph, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// DFS function
bool dfs(Graph* graph, int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    Node* temp = graph->adj[node];

    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(graph, neighbor, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = false; // backtrack
    return false;
}

// Function to check cycle
bool hasCycle(Graph* graph) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, recStack))
                return true;
        }
    }
    return false;
}

// Main function
int main() {
    int V = 4;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1); // cycle

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}