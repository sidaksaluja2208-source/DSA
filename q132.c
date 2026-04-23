/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 2000

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int V;
    Node* adj[MAX];
} Graph;

// Create node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge (b -> a)
void addEdge(Graph* graph, int b, int a) {
    Node* newNode = createNode(a);
    newNode->next = graph->adj[b];
    graph->adj[b] = newNode;
}

// DFS for cycle detection
bool dfs(Graph* graph, int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    Node* temp = graph->adj[node];

    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            if (dfs(graph, neighbor, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = false;
    return false;
}

// Check if all courses can be finished
bool canFinish(int numCourses, int prerequisites[][2], int size) {
    Graph* graph = createGraph(numCourses);

    // Build graph
    for (int i = 0; i < size; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        addEdge(graph, b, a);
    }

    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, recStack))
                return false; // cycle exists
        }
    }

    return true;
}

// Main function (example test)
int main() {
    int numCourses = 2;

    int prerequisites[][2] = {{1, 0}, {0, 1}};
    int size = 2;

    if (canFinish(numCourses, prerequisites, size))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}