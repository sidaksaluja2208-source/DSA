/*Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-

 

Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
 

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
 

Constraints:
1 ≤ V ≤ 105*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int V;
int *adj[MAX];
int adjSize[MAX];

int disc[MAX], low[MAX], parent[MAX], visited[MAX];
int ap[MAX];
int timeCounter;

void dfs(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent[u] == -1 && children > 1)
                ap[u] = 1;

            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent[u]) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(MAX * sizeof(int));
        adjSize[i] = 0;
        visited[i] = 0;
        parent[i] = -1;
        ap[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    timeCounter = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }

    int *result = (int*)malloc(V * sizeof(int));
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (ap[i])
            result[count++] = i;
    }

    if (count == 0) {
        printf("-1\n");
    } else {
        qsort(result, count, sizeof(int), cmp);
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}