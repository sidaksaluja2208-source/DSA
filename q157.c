/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph structure
struct Node* adj[MAX];

// Min Heap structure
struct HeapNode {
    int vertex;
    int dist;
};

struct HeapNode heap[MAX];
int heapSize = 0;

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int index) {
    while (index && heap[index].dist < heap[(index - 1) / 2].dist) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int vertex, int dist) {
    heap[heapSize].vertex = vertex;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

// Extract minimum
struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Create new adjacency node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;
}

// Dijkstra function
void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        struct HeapNode top = pop();
        int u = top.vertex;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}

// Main function
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < MAX; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // undirected graph
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}