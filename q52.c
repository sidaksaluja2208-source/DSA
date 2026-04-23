#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} MyLinkedList;

// Create the linked list
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;

    Node* curr;

    if (index < obj->size / 2) {
        curr = obj->head;
        for (int i = 0; i < index; i++)
            curr = curr->next;
    } else {
        curr = obj->tail;
        for (int i = obj->size - 1; i > index; i--)
            curr = curr->prev;
    }

    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    node->prev = NULL;

    if (obj->size == 0) {
        obj->head = obj->tail = node;
    } else {
        obj->head->prev = node;
        obj->head = node;
    }

    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = obj->tail;

    if (obj->size == 0) {
        obj->head = obj->tail = node;
    } else {
        obj->tail->next = node;
        obj->tail = node;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;

    Node* curr;

    if (index < obj->size / 2) {
        curr = obj->head;
        for (int i = 0; i < index; i++)
            curr = curr->next;
    } else {
        curr = obj->tail;
        for (int i = obj->size - 1; i >= index; i--)
            curr = curr->prev;
    }

    Node* prevNode = curr->prev;

    node->next = curr;
    node->prev = prevNode;
    prevNode->next = node;
    curr->prev = node;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;

    Node* curr;

    if (index == 0) {
        curr = obj->head;
        obj->head = curr->next;
        if (obj->head) obj->head->prev = NULL;
        else obj->tail = NULL;
    }
    else if (index == obj->size - 1) {
        curr = obj->tail;
        obj->tail = curr->prev;
        if (obj->tail) obj->tail->next = NULL;
        else obj->head = NULL;
    }
    else {
        if (index < obj->size / 2) {
            curr = obj->head;
            for (int i = 0; i < index; i++)
                curr = curr->next;
        } else {
            curr = obj->tail;
            for (int i = obj->size - 1; i > index; i--)
                curr = curr->prev;
        }

        Node* prevNode = curr->prev;
        Node* nextNode = curr->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    free(curr);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}

// -------------------------
// Example main() to test
// -------------------------

int main() {
    MyLinkedList* myLinkedList = myLinkedListCreate();

    myLinkedListAddAtHead(myLinkedList, 1);        // [1]
    myLinkedListAddAtTail(myLinkedList, 3);        // [1,3]
    myLinkedListAddAtIndex(myLinkedList, 1, 2);    // [1,2,3]

    printf("%d\n", myLinkedListGet(myLinkedList, 1));  // 2

    myLinkedListDeleteAtIndex(myLinkedList, 1);    // [1,3]

    printf("%d\n", myLinkedListGet(myLinkedList, 1));  // 3

    myLinkedListFree(myLinkedList);
    return 0;
}