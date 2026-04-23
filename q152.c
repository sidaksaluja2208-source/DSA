/*Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 101

// -------- Node Structure --------
struct Node {
    int val;
    int numNeighbors;
    struct Node* neighbors[MAX];
};

// Map for visited nodes (original -> clone)
struct Node* visited[MAX];

// -------- Create Node --------
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = 0;
    return node;
}

// -------- Clone Graph (DFS) --------
struct Node* cloneGraph(struct Node* node) {
    if (node == NULL)
        return NULL;

    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node* clone = createNode(node->val);
    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[clone->numNeighbors++] =
            cloneGraph(node->neighbors[i]);
    }

    return clone;
}

// -------- Build Graph from Input --------
struct Node* buildGraph(int n) {
    struct Node* nodes[MAX];

    // create nodes
    for (int i = 1; i <= n; i++) {
        nodes[i] = createNode(i);
    }

    // input adjacency list
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k); // number of neighbors

        for (int j = 0; j < k; j++) {
            int neighbor;
            scanf("%d", &neighbor);
            nodes[i]->neighbors[nodes[i]->numNeighbors++] = nodes[neighbor];
        }
    }

    return nodes[1]; // return starting node
}

// -------- Print Graph (BFS) --------
void printGraph(struct Node* node, int n) {
    int visitedPrint[MAX] = {0};
    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = node;
    visitedPrint[node->val] = 1;

    while (front < rear) {
        struct Node* curr = queue[front++];

        printf("%d: ", curr->val);
        for (int i = 0; i < curr->numNeighbors; i++) {
            printf("%d ", curr->neighbors[i]->val);

            if (!visitedPrint[curr->neighbors[i]->val]) {
                visitedPrint[curr->neighbors[i]->val] = 1;
                queue[rear++] = curr->neighbors[i];
            }
        }
        printf("\n");
    }
}

// -------- Main --------
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency list (for each node: number of neighbors followed by neighbors):\n");

    struct Node* original = buildGraph(n);

    // initialize visited array
    for (int i = 0; i < MAX; i++) {
        visited[i] = NULL;
    }

    struct Node* cloned = cloneGraph(original);

    printf("\nCloned Graph:\n");
    printGraph(cloned, n);

    return 0;
}