/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// Check if deque is empty
int empty() {
    return (front == -1);
}

// Check if deque is full
int isFull() {
    return (rear == MAX - 1);
}

// Insert at front
void push_front(int value) {
    if (front == 0) {
        printf("Deque overflow at front\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = value;
}

// Insert at rear
void push_back(int value) {
    if (isFull()) {
        printf("Deque overflow at rear\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}

// Delete from front
void pop_front() {
    if (empty()) {
        printf("Deque underflow\n");
        return;
    }

    printf("Removed from front: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Delete from rear
void pop_back() {
    if (empty()) {
        printf("Deque underflow\n");
        return;
    }

    printf("Removed from rear: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// Get front element
int getFront() {
    if (empty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[front];
}

// Get rear element
int getBack() {
    if (empty()) {
        printf("Deque is empty\n");
        return -1;
    }
    return deque[rear];
}

// Get size
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

// Clear deque
void clear() {
    front = rear = -1;
    printf("Deque cleared\n");
}

// Reverse deque
void reverse() {
    if (empty()) return;

    int i = front, j = rear, temp;
    while (i < j) {
        temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

// Sort deque (ascending)
void sortDeque() {
    int i, j, temp;

    for (i = front; i <= rear; i++) {
        for (j = i + 1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

// Display deque
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    printf("Front element: %d\n", getFront());
    printf("Rear element: %d\n", getBack());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    display();

    reverse();
    printf("After reverse:\n");
    display();

    sortDeque();
    printf("After sort:\n");
    display();

    clear();
    display();

    return 0;
}