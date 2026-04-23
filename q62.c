/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/


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
        if (slow == fast)
            break;
    }

    // If no cycle is detected
    if (!fast || !fast->next)
        return NULL;

    // Step 2: Find the start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;  // start of cycle
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
            tail = node;
        }
    }

    // Read the position to create a cycle
    scanf("%d", &pos);
    if (pos >= 0) {
        cycleNode = head;
        for (int i = 0; i < pos; i++) {
            cycleNode = cycleNode->next;
        }
        tail->next = cycleNode; // Create cycle
    }

    struct ListNode* result = detectCycle(head);
    if (result) {
        printf("cycle starts at node with value: %d\n", result->val);
    } else {
        printf("no cycle\n");
    }

    return 0;
}