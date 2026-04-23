/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
 
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Reverse linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check palindrome
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    struct ListNode *secondHalf = reverseList(slow);

    // Step 3: Compare first and second halves
    struct ListNode *first = head, *second = secondHalf;
    while (second) {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("false");
        return 0;
    }

    // Build linked list
    struct ListNode *head = NULL, *temp = NULL;

    for (int i = 0; i < n; i++) {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        scanf("%d", &newNode->val);
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Check palindrome
    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}