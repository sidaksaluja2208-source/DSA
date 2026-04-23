/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/

#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX], indegree[MAX] = {0};

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");
    int count = 0;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (j = 0; j < n; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    if (count != n)
        printf("\nCycle detected! No Topological Sort possible.\n");

    return 0;
}