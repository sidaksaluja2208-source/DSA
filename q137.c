/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Graph
typedef struct {
    Node* head[MAX];
} Graph;

// Min Heap Node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// Min Heap
typedef struct {
    int size;
    HeapNode heap[MAX];
} MinHeap;

// Create new adjacency node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(Graph* g, int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = g->head[u];
    g->head[u] = newNode;
}

// Swap heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

// Extract min
HeapNode extractMin(MinHeap* h) {
    HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

// Insert into heap
void insertHeap(MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;

    while (i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dijkstra Algorithm
void dijkstra(Graph* g, int V, int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    insertHeap(&h, src, 0);

    while (h.size > 0) {
        HeapNode minNode = extractMin(&h);
        int u = minNode.vertex;

        Node* temp = g->head[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main
int main() {
    int V = 5;
    Graph g;

    for (int i = 0; i < V; i++)
        g.head[i] = NULL;

    addEdge(&g, 0, 1, 10);
    addEdge(&g, 0, 4, 5);
    addEdge(&g, 1, 2, 1);
    addEdge(&g, 4, 1, 3);
    addEdge(&g, 4, 2, 9);
    addEdge(&g, 2, 3, 4);
    addEdge(&g, 3, 0, 7);

    dijkstra(&g, V, 0);

    return 0;
}