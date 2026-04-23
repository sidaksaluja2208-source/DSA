/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Build linked list from array
struct Node* buildList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = createNode(arr[0]);
    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = createNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Count length of linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Find intersection node
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Move the longer list ahead
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    // Move both simultaneously
    while (head1 && head2) {
        if (head1->data == head2->data)  // same value means intersection (as per problem)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m;

    // Read first list
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr1[i]);

    // Read second list
    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++) scanf("%d", &arr2[i]);

    // Build lists
    struct Node* head1 = buildList(arr1, n);
    struct Node* head2 = buildList(arr2, m);

    // Find intersection
    struct Node* intersect = findIntersection(head1, head2);

    if (intersect)
        printf("%d", intersect->data);
    else
        printf("No Intersection");

    return 0;
}