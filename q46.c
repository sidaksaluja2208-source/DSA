/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of ListNode
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Create a new node
ListNode* newNode(int value) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

// Detect cycle using Floyd's Algorithm
bool hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;            // move 1 step
        fast = fast->next->next;      // move 2 steps

        if (slow == fast)             // pointers meet → cycle exists
            return true;
    }
    return false; // reached end → no cycle
}

int main() {
    int n, pos, value;

    // Read number of nodes
    scanf("%d", &n);

    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* cycleNode = NULL;

    // Read values and build list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        ListNode* node = newNode(value);

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        // Keep track of the node at index "pos"
        if (i == 0) cycleNode = head;
    }

    // Read pos (cycle position)
    scanf("%d", &pos);

    // If pos >= 0, link tail->next to the pos-th node to form a cycle
    if (pos >= 0) {
        ListNode* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        tail->next = temp;  // create the cycle
    }

    // Check for cycle
    if (hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}