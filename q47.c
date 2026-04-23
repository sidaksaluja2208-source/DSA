/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of key
Node* deleteKey(Node* head, int key) {
    if (head == NULL)
        return head;

    // If head itself is the key
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    return head; // key not found, return unchanged list
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, key, value;

    scanf("%d", &n);

    Node* head = NULL;

    // Read list elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Read key to delete
    scanf("%d", &key);

    // Delete first occurrence
    head = deleteKey(head, key);

    // Print updated list
    printList(head);

    return 0;
}