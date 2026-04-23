/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Graph as adjacency list
struct Node* adj[MAX];
int visited[MAX];

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS using recursion
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
        temp = temp->next;
    }
}

int main() {
    int n, e, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    DFS(s);

    return 0;
}