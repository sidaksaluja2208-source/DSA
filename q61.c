/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Stack {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int value) {
    if (s->top < MAX_SIZE - 1) {
        s->arr[++s->top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

void pop(Stack* s) {
    if (s->top >= 0) {
        printf("%d\n", s->arr[s->top--]);
    } else {
        printf("Stack Underflow\n");
    }
}
void display(Stack* s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);
    int n, op, value;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &value);
            push(&s, value);
        } else if (op == 2) {
            pop(&s);
        } else if (op == 3) {
            display(&s);
        }
    }
    return 0;
}

