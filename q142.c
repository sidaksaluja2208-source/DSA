/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
 

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

// Manhattan distance
int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int minCostConnectPoints(int** points, int n) {
    int *minDist = (int*)malloc(n * sizeof(int));
    int *visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        minDist[i] = INT_MAX;

    minDist[0] = 0;
    int totalCost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        // Find minimum distance unvisited node
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minDist[u];

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = manhattan(points[u][0], points[u][1],
                                     points[v][0], points[v][1]);

                minDist[v] = min(minDist[v], dist);
            }
        }
    }

    free(minDist);
    free(visited);

    return totalCost;
}

int main() {
    int n;
    scanf("%d", &n);

    int** points = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        points[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int result = minCostConnectPoints(points, n);
    printf("%d\n", result);

    for (int i = 0; i < n; i++)
        free(points[i]);
    free(points);

    return 0;
}