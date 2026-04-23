/*There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 

Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
 

Constraints:

n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

// DFS function
void dfs(int room, int roomsSize, int roomsColSize[], int rooms[][MAX], bool visited[]) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];

        // Safety check
        if (key >= 0 && key < roomsSize && !visited[key]) {
            dfs(key, roomsSize, roomsColSize, rooms, visited);
        }
    }
}

// Function to check if all rooms can be visited
bool canVisitAllRooms(int roomsSize, int roomsColSize[], int rooms[][MAX]) {
    bool visited[MAX] = {false};

    // Start from room 0
    dfs(0, roomsSize, roomsColSize, rooms, visited);

    // Check if all rooms visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}

// Driver code
int main() {
    int roomsSize = 4;

    // Number of keys in each room
    int roomsColSize[] = {1, 1, 1, 0};

    // Adjacency list representation
    int rooms[MAX][MAX] = {0};

    // Fill rooms manually
    rooms[0][0] = 1;  // room 0 → key 1
    rooms[1][0] = 2;  // room 1 → key 2
    rooms[2][0] = 3;  // room 2 → key 3
    // room 3 has 0 keys

    if (canVisitAllRooms(roomsSize, roomsColSize, rooms))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}