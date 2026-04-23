/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

int findMinIndex() {
    if (size == 0)
        return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void insert(int x) {
    if (size < MAX) {
        pq[size++] = x;
    }
}

void deleteElement() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = findMinIndex();
    printf("%d\n", pq[minIndex]);
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0) {
            deleteElement();
        }
        else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}