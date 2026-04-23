/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Create a new node
ListNode* createNode(int value) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

// Insert at end
ListNode* insertEnd(ListNode* head, int value) {
    ListNode* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Remove all nodes equal to val
ListNode* removeElements(ListNode* head, int val) {
    // Dummy node
    ListNode* dummy = createNode(0);
    dummy->next = head;

    ListNode* curr = dummy;

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}

// Print list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, val, x;

    scanf("%d", &n);

    ListNode* head = NULL;

    // read list elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    // read value to remove
    scanf("%d", &val);

    // remove occurrences
    head = removeElements(head, val);

    // print result
    printList(head);

    return 0;
}