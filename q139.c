/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

// Edge structure
struct Edge {
    int u, v, w;
};

int main() {
    int n, m;

    // Input number of vertices and edges
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int source;
    scanf("%d", &source);

    int dist[n];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    // Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // Output shortest distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    printf("\n");

    return 0;
}