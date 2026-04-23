/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.

Examples:

Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]


Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 
Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]

Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: V = 2, E = 1, edges[][] = [[0, 1]]
Output: 2
Constraints:
1 ≤ V ≤ 106
0 ≤ E ≤ 106
0 ≤ edges[i][0], edges[i][1] < V

 

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
struct Node* rev[MAX];

int visited[MAX];
int stack[MAX];
int top = -1;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Node* graph[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = graph[u];
    graph[u] = node;
}

// First DFS (fill stack)
void dfs1(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex])
            dfs1(temp->vertex);
        temp = temp->next;
    }

    stack[++top] = v;
}

// Second DFS (on reversed graph)
void dfs2(int v) {
    visited[v] = 1;

    struct Node* temp = rev[v];
    while (temp) {
        if (!visited[temp->vertex])
            dfs2(temp->vertex);
        temp = temp->next;
    }
}

// Kosaraju function
int kosaraju(int V) {
    // Step 1: DFS and fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs1(i);
    }

    // Step 2: Reset visited
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // Step 3: Process stack
    int scc = 0;
    while (top >= 0) {
        int v = stack[top--];

        if (!visited[v]) {
            dfs2(v);
            scc++;
        }
    }

    return scc;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        rev[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);   // original graph
        addEdge(rev, v, u);   // reversed graph
    }

    int result = kosaraju(V);
    printf("%d\n", result);

    return 0;
}