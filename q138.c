/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 105

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap
typedef struct {
    int node, dist;
} HeapNode;

HeapNode heap[10000];
int size = 0;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void push(int node, int dist) {
    int i = size++;
    heap[i].node = node;
    heap[i].dist = dist;

    while (i > 0 && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (1) {
        int smallest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < size && heap[l].dist < heap[smallest].dist)
            smallest = l;
        if (r < size && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return root;
}

// Network Delay Time
int networkDelayTime(int times[][3], int timesSize, int n, int k) {
    // Initialize graph
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < timesSize; i++) {
        addEdge(times[i][0], times[i][1], times[i][2]);
    }

    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[k] = 0;
    size = 0;
    push(k, 0);

    while (size > 0) {
        HeapNode curr = pop();
        int u = curr.node;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            return -1;
        if (dist[i] > maxTime)
            maxTime = dist[i];
    }

    return maxTime;
}

// Driver
int main() {
    int times[][3] = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;

    int result = networkDelayTime(times, 3, n, k);
    printf("Output: %d\n", result);

    return 0;
}