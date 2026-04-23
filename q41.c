/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
struct Node* createLinkedList(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;

    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        current->next = newNode;
        current = newNode;
    }

    return head;
}

// Function to traverse and print linked list
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = createLinkedList(arr, n);
    traverse(head);

    return 0;
}