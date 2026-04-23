/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
};

// Create a new polynomial node
struct PolyNode* createNode(int coeff, int exp) {
    struct PolyNode* newNode = (struct PolyNode*) malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert in descending exponent order
void insertTerm(struct PolyNode** head, int coeff, int exp) {
    struct PolyNode* newNode = createNode(coeff, exp);

    // If list is empty or new exponent is larger, insert at head
    if (*head == NULL || exp > (*head)->exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct PolyNode* temp = *head;

    // Traverse to find correct position
    while (temp->next != NULL && temp->next->exp > exp)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Print polynomial in correct form
void printPolynomial(struct PolyNode* head) {
    struct PolyNode* temp = head;

    while (temp != NULL) {
        // Print coefficient
        printf("%d", temp->coeff);

        // Print exponent part
        if (temp->exp > 1)
            printf("x^%d", temp->exp);
        else if (temp->exp == 1)
            printf("x");

        // Print + if not last term
        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    printf("\n");
}

// Free memory
void freePolynomial(struct PolyNode* head) {
    struct PolyNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, coeff, exp;
    struct PolyNode* poly = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }

    printPolynomial(poly);
    freePolynomial(poly);
    return 0;
}