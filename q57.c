


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k;
    scanf("%d", &n);

    // Create linked list
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &k);

    // Edge cases
    if (n == 0 || k == 0 || k % n == 0) {
        temp = head;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Make list circular
    temp->next = head;

    // Find new head position
    int steps = n - (k % n);
    struct Node *curr = head;

    for (int i = 1; i < steps; i++) {
        curr = curr->next;
    }

    // curr is now at (n - k)th node
    head = curr->next;      // New head
    curr->next = NULL;      // Break the cycle

    // Print rotated list
    temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}