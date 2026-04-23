/*Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

// Initialize deque
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(sizeof(int) * k);
    obj->capacity = k;
    obj->front = -1;
    obj->rear = -1;
    obj->size = 0;
    return obj;
}

// Check if empty
bool isEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

// Check if full
bool isFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

// Insert at front
bool insertFront(MyCircularDeque* obj, int value) {
    if (isFull(obj))
        return false;

    if (isEmpty(obj)) {
        obj->front = obj->rear = 0;
    } else {
        obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    }

    obj->arr[obj->front] = value;
    obj->size++;
    return true;
}

// Insert at rear
bool insertLast(MyCircularDeque* obj, int value) {
    if (isFull(obj))
        return false;

    if (isEmpty(obj)) {
        obj->front = obj->rear = 0;
    } else {
        obj->rear = (obj->rear + 1) % obj->capacity;
    }

    obj->arr[obj->rear] = value;
    obj->size++;
    return true;
}

// Delete from front
bool deleteFront(MyCircularDeque* obj) {
    if (isEmpty(obj))
        return false;

    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
    }

    obj->size--;
    return true;
}

// Delete from rear
bool deleteLast(MyCircularDeque* obj) {
    if (isEmpty(obj))
        return false;

    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else {
        obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    }

    obj->size--;
    return true;
}

// Get front element
int getFront(MyCircularDeque* obj) {
    if (isEmpty(obj))
        return -1;
    return obj->arr[obj->front];
}

// Get rear element
int getRear(MyCircularDeque* obj) {
    if (isEmpty(obj))
        return -1;
    return obj->arr[obj->rear];
}

// Free memory
void freeDeque(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}

// Demonstration in main
int main() {
    MyCircularDeque* dq = myCircularDequeCreate(3);

    printf("%d\n", insertLast(dq, 1));   // true
    printf("%d\n", insertLast(dq, 2));   // true
    printf("%d\n", insertFront(dq, 3));  // true
    printf("%d\n", insertFront(dq, 4));  // false (full)

    printf("%d\n", getRear(dq));         // 2
    printf("%d\n", isFull(dq));          // true

    printf("%d\n", deleteLast(dq));      // true
    printf("%d\n", insertFront(dq, 4));  // true
    printf("%d\n", getFront(dq));        // 4

    freeDeque(dq);
    return 0;
}