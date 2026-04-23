/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int x, y, time;
} Node;

typedef struct {
    Node items[MAX*MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node val) {
    q->items[q->rear++] = val;
}

Node dequeue(Queue* q) {
    return q->items[q->front++];
}

int orangesRotting(int** grid, int m, int n) {
    Queue q;
    initQueue(&q);
    int fresh = 0;
    int maxTime = 0;

    // Collect rotten oranges and count fresh ones
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                enqueue(&q, (Node){i, j, 0});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    // BFS
    while (!isEmpty(&q)) {
        Node cur = dequeue(&q);
        maxTime = cur.time;

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dirs[d][0];
            int ny = cur.y + dirs[d][1];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                fresh--;
                enqueue(&q, (Node){nx, ny, cur.time + 1});
            }
        }
    }

    return fresh == 0 ? maxTime : -1;
}

int main() {
    int m, n;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int** grid = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = orangesRotting(grid, m, n);
    printf("Output: %d\n", result);

    for (int i = 0; i < m; i++) free(grid[i]);
    free(grid);

    return 0;
}
