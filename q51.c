/*roblem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/


#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    int n, value;
    scanf("%d", &n);

    Node* head = NULL;
    Node* tail = NULL;

    // Insert nodes one by one
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        Node* newNode = createNode(value);

        if (head == NULL) {
            // First node
            head = tail = newNode;
        } else {
            // Append at the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Traverse forward and print
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }

    return 0;
}