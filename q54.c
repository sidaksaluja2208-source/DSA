/*Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.

Examples:

Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 

The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 

A loop is present in the list, and it is removed.
Constraints:
1 ≤ size of linked list ≤ 105*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Create cycle at pos (0-based); if pos = -1 → no cycle
void createCycle(struct Node* head, int pos) {
    if (pos < 0) return;

    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int index = 0;

    while (temp->next) {
        if (index == pos)
            loopNode = temp;
        temp = temp->next;
        index++;
    }

    // Create the loop
    temp->next = loopNode;
}

// Remove cycle if exists
int removeCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return 0;

    struct Node* slow = head;
    struct Node* fast = head;

    // Step 1: Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return 0; // No cycle

    // Step 2: Find start of cycle
    slow = head;

    if (slow == fast) {
        // Loop starts at head
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Step 3: Break the cycle
    fast->next = NULL;
    return 1;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    scanf("%d", &pos);

    // Create cycle at pos
    createCycle(head, pos);

    // Remove cycle and print result
    if (removeCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}