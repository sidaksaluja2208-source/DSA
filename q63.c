/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = top;
    top = top->next;
    free(temp);
}

// Display stack elements
void display() {
    struct Node* temp = top;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, m, value;

    // number of elements to push
    scanf("%d", &n);

    // pushing elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // number of pops
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    // display remaining stack
    display();

    return 0;
}