/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Create new node
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Append node at end
void append(struct ListNode** head, int val) {
    struct ListNode* newNode = createNode(val);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct ListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Push on stack
void push(int* stack, int* top, int val) {
    stack[++(*top)] = val;
}

// Pop from stack
int pop(int* stack, int* top) {
    return stack[(*top)--];
}

// Add two numbers without reversing linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int s1[110], s2[110];
    int top1 = -1, top2 = -1;

    // Push digits from l1
    struct ListNode* temp = l1;
    while (temp) {
        push(s1, &top1, temp->val);
        temp = temp->next;
    }

    // Push digits from l2
    temp = l2;
    while (temp) {
        push(s2, &top2, temp->val);
        temp = temp->next;
    }

    int carry = 0;
    struct ListNode* result = NULL;

    // Pop and add digits
    while (top1 >= 0 || top2 >= 0 || carry) {
        int a = (top1 >= 0) ? pop(s1, &top1) : 0;
        int b = (top2 >= 0) ? pop(s2, &top2) : 0;

        int sum = a + b + carry;
        carry = sum / 10;
        sum = sum % 10;

        // Insert at front
        struct ListNode* newNode = createNode(sum);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

// Print linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Free memory
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n1, n2, val;

    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    // Input first list
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        append(&l1, val);
    }

    // Input second list
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        append(&l2, val);
    }

    // Add numbers
    struct ListNode* result = addTwoNumbers(l1, l2);

    // Print result
    printList(result);

    // Free memory
    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}