/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/

#include <stdio.h>
#include <stdlib.h>

/* ---------- MIN HEAP ---------- */
typedef struct MinHeap {
    int *arr;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->arr = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void minHeapInsert(MinHeap *minHeap, int val) {
    if (minHeap->size == minHeap->capacity) {
        return; // Heap is full
    }
    int i = minHeap->size++;
    minHeap->arr[i] = val;

    while (i > 0 && minHeap->arr[(i - 1) / 2] > minHeap->arr[i]) {
        swap(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int minHeapExtract(MinHeap *minHeap) {
    if (minHeap->size == 0) {
        return -1; // Heap is empty
    }
    int root = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[--minHeap->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < minHeap->size && minHeap->arr[left] < minHeap->arr[smallest]) {
            smallest = left;
        }

        if (right < minHeap->size && minHeap->arr[right] < minHeap->arr[smallest]) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        swap(&minHeap->arr[i], &minHeap->arr[smallest]);
        i = smallest;
    }

    return root;
}

/* ---------- MAX HEAP ---------- */
typedef struct MaxHeap {
    int *arr;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *maxHeap = (MaxHeap*)malloc(sizeof(MaxHeap));
    maxHeap->arr = (int*)malloc(capacity * sizeof(int));
    maxHeap->size = 0;
    maxHeap->capacity = capacity;
    return maxHeap;
}

void maxHeapInsert(MaxHeap *maxHeap, int val) {
    if (maxHeap->size == maxHeap->capacity) {
        return; // Heap is full
    }
    int i = maxHeap->size++;
    maxHeap->arr[i] = val;

    while (i > 0 && maxHeap->arr[(i - 1) / 2] < maxHeap->arr[i]) {
        swap(&maxHeap->arr[i], &maxHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int maxHeapExtract(MaxHeap *maxHeap) {
    if (maxHeap->size == 0) {
        return -1; // Heap is empty
    }
    int root = maxHeap->arr[0];
    maxHeap->arr[0] = maxHeap->arr[--maxHeap->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < maxHeap->size && maxHeap->arr[left] > maxHeap->arr[largest]) {
            largest = left;
        }

        if (right < maxHeap->size && maxHeap->arr[right] > maxHeap->arr[largest]) {
            largest = right;
        }

        if (largest == i) {
            break;
        }

        swap(&maxHeap->arr[i], &maxHeap->arr[largest]);
        i = largest;
    }

    return root;
}

/* ---------- MEDIAN FINDER ---------- */
typedef struct MedianFinder {
    MaxHeap *maxHeap;
    MinHeap *minHeap;
} MedianFinder;

MedianFinder* createMedianFinder(int capacity) {
    MedianFinder *mf = (MedianFinder*)malloc(sizeof(MedianFinder));
    mf->maxHeap = createMaxHeap(capacity);
    mf->minHeap = createMinHeap(capacity);
    return mf;
}   

void addNum(MedianFinder *mf, int num) {
    if (mf->maxHeap->size == 0 || num <= mf->maxHeap->arr[0]) {
        maxHeapInsert(mf->maxHeap, num);
    } else {
        minHeapInsert(mf->minHeap, num);
    }

    // balance heaps
    if (mf->maxHeap->size > mf->minHeap->size + 1) {
        minHeapInsert(mf->minHeap, maxHeapExtract(mf->maxHeap));
    }

    if (mf->minHeap->size > mf->maxHeap->size) {
        maxHeapInsert(mf->maxHeap, minHeapExtract(mf->minHeap));
    }
}

double findMedian(MedianFinder *mf) {
    if (mf->maxHeap->size == mf->minHeap->size) {
        return (mf->maxHeap->arr[0] + mf->minHeap->arr[0]) / 2.0;
    }

    return mf->maxHeap->arr[0];
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    MedianFinder *mf = createMedianFinder(100);

    addNum(mf, 1);
    printf("Median: %.1f\n", findMedian(mf)); // 1.0

    addNum(mf, 2);
    printf("Median: %.1f\n", findMedian(mf)); // 1.5

    addNum(mf, 3);
    printf("Median: %.1f\n", findMedian(mf)); // 2.0

    return 0;
}

