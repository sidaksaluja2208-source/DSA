/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue implementation
#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// BFS function
void bfs(int n, int adj[n][n], int s) {
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    Queue q;
    initQueue(&q);

    visited[s] = true;
    enqueue(&q, s);

    printf("BFS Traversal: ");
    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                enqueue(&q, v);
            }
        }
    }
    printf("\n");
}

// Driver code
int main() {
    int n, s;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &s);

    bfs(n, adj, s);

    return 0;
}
