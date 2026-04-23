/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int adj[MAX][MAX];
int state[MAX];   // 0 = unvisited, 1 = visiting, 2 = visited
int result[MAX];
int index;
int V;

// DFS with cycle detection
int dfs(int node) {
    if (state[node] == 1) return 0; // cycle found
    if (state[node] == 2) return 1; // already processed

    state[node] = 1; // mark visiting

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!dfs(i)) return 0;
        }
    }

    state[node] = 2; // mark visited
    result[index++] = node; // add to result

    return 1;
}

// Function to find order
void findOrder(int numCourses, int prerequisites[][2], int prereqSize) {
    V = numCourses;
    index = 0;

    // Initialize graph
    for (int i = 0; i < V; i++) {
        state[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    // Build graph (bi -> ai)
    for (int i = 0; i < prereqSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        adj[b][a] = 1;
    }

    // DFS for all nodes
    for (int i = 0; i < V; i++) {
        if (state[i] == 0) {
            if (!dfs(i)) {
                printf("[]\n"); // cycle → no solution
                return;
            }
        }
    }

    // Print result in reverse order
    printf("[");
    for (int i = V - 1; i >= 0; i--) {
        printf("%d", result[i]);
        if (i > 0) printf(", ");
    }
    printf("]\n");
}

int main() {
    int numCourses = 4;
    int prerequisites[][2] = {{1,0},{2,0},{3,1},{3,2}};
    int prereqSize = 4;

    findOrder(numCourses, prerequisites, prereqSize);

    return 0;
}