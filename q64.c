/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Push
void push(Stack *s, int val) {
    s->arr[++(s->top)] = val;
}

// Pop
int pop(Stack *s) {
    return s->arr[(s->top)--];
}

// Top element
int top(Stack *s) {
    return s->arr[s->top];
}

// Check empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// MinStack structure
typedef struct {
    Stack mainStack;
    Stack minStack;
} MinStack;

// Initialize MinStack
void MinStack_init(MinStack *obj) {
    init(&obj->mainStack);
    init(&obj->minStack);
}

// Push element
void MinStack_push(MinStack *obj, int val) {
    push(&obj->mainStack, val);

    if (isEmpty(&obj->minStack) || val <= top(&obj->minStack)) {
        push(&obj->minStack, val);
    }
}

// Pop element
void MinStack_pop(MinStack *obj) {
    int popped = pop(&obj->mainStack);

    if (popped == top(&obj->minStack)) {
        pop(&obj->minStack);
    }
}

// Get top
int MinStack_top(MinStack *obj) {
    return top(&obj->mainStack);
}

// Get minimum
int MinStack_getMin(MinStack *obj) {
    return top(&obj->minStack);
}

// Demonstration
int main() {
    MinStack minStack;

    MinStack_init(&minStack);

    MinStack_push(&minStack, -2);
    MinStack_push(&minStack, 0);
    MinStack_push(&minStack, -3);

    printf("%d\n", MinStack_getMin(&minStack)); // -3

    MinStack_pop(&minStack);

    printf("%d\n", MinStack_top(&minStack));    // 0
    printf("%d\n", MinStack_getMin(&minStack)); // -2

    return 0;
}