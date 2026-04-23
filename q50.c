/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?*/


#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Floyd’s Cycle Detection Algorithm
struct ListNode* detectCycle(struct ListNode* head) {
    if (!head || !head->next)
        return NULL;

    struct ListNode *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find cycle start
            struct ListNode *p1 = head;
            struct ListNode *p2 = slow;

            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;  // start of cycle
        }
    }

    return NULL; // no cycle
}

int main() {
    int n, pos;
    scanf("%d", &n);

    if (n == 0) {
        printf("no cycle\n");
        return 0;
    }

    struct ListNode *head = NULL, *tail = NULL, *cycleNode = NULL;

    // Read list values
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct ListNode* node = newNode(val);

        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }

    // Read cycle position
    scanf("%d", &pos);

    // Create cycle if pos != -1
    if (pos != -1) {
        struct ListNode *temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        tail->next = temp;
    }

    // Detect cycle
    struct ListNode* start = detectCycle(head);

    if (start)
        printf("tail connects to node index %d\n", pos);
    else
        printf("no cycle\n");

    return 0;
}