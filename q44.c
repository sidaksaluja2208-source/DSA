/*Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node.
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Function to reverse the linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Save next node
        curr->next = prev;   // Reverse the pointer
        prev = curr;         // Move prev forward
        curr = next;         // Move curr forward
    }

    return prev;  // New head of reversed list
}

// Create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Build linked list: 1 → 2 → 3 → 4 → 5
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original List: ");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}