/*There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency list
int *adj[MAX];
int size[MAX];

// Arrays
int disc[MAX], low[MAX], visited[MAX];
int timeCounter = 0;

// Store result
int result[MAX][2];
int resultSize = 0;

// DFS function
void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (!visited[v]) {
            dfs(v, u);

            // Update low value
            if (low[v] < low[u])
                low[u] = low[v];

            // Check for bridge
            if (low[v] > disc[u]) {
                result[resultSize][0] = u;
                result[resultSize][1] = v;
                resultSize++;
            }
        } else {
            // Back edge
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)malloc(MAX * sizeof(int));
        size[i] = 0;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    // Run DFS from node 0
    dfs(0, -1);

    // Output result
    for (int i = 0; i < resultSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
    }

    return 0;
}