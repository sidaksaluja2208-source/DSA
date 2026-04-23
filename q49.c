/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/



#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to count occurrences of a key
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    while (head != NULL) {
        if (head->data == key) {
            count++;
        }
        head = head->next;
    }
    return count;
}

int main() {
    int n, key, value;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create linked list dynamically
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    scanf("%d", &key);

    // Count occurrences
    int result = countOccurrences(head, key);

    // Output result
    printf("%d\n", result);

    return 0;
}