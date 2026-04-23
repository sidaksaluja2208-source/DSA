/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 */

 #include <stdio.h>
#include <stdlib.h>

#define MAX 50000

// Max Heap
int maxHeap[MAX];
int maxSize = 0;

// Min Heap
int minHeap[MAX];
int minSize = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* ---------- MAX HEAP ---------- */

void maxHeapInsert(int val)
{
    int i = maxSize++;
    maxHeap[i] = val;

    while(i > 0 && maxHeap[(i-1)/2] < maxHeap[i])
    {
        swap(&maxHeap[i], &maxHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int maxHeapExtract()
{
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];

    int i = 0;

    while(1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if(left < maxSize && maxHeap[left] > maxHeap[largest])
            largest = left;

        if(right < maxSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if(largest == i)
            break;

        swap(&maxHeap[i], &maxHeap[largest]);
        i = largest;
    }

    return root;
}

/* ---------- MIN HEAP ---------- */

void minHeapInsert(int val)
{
    int i = minSize++;
    minHeap[i] = val;

    while(i > 0 && minHeap[(i-1)/2] > minHeap[i])
    {
        swap(&minHeap[i], &minHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int minHeapExtract()
{
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];

    int i = 0;

    while(1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < minSize && minHeap[left] < minHeap[smallest])
            smallest = left;

        if(right < minSize && minHeap[right] < minHeap[smallest])
            smallest = right;

        if(smallest == i)
            break;

        swap(&minHeap[i], &minHeap[smallest]);
        i = smallest;
    }

    return root;
}

/* ---------- MEDIAN FINDER ---------- */

void addNum(int num)
{
    if(maxSize == 0 || num <= maxHeap[0])
        maxHeapInsert(num);
    else
        minHeapInsert(num);

    // balance heaps
    if(maxSize > minSize + 1)
        minHeapInsert(maxHeapExtract());

    if(minSize > maxSize)
        maxHeapInsert(minHeapExtract());
}

double findMedian()
{
    if(maxSize == minSize)
        return (maxHeap[0] + minHeap[0]) / 2.0;

    return maxHeap[0];
}

/* ---------- MAIN ---------- */

int main()
{
    addNum(1);
    addNum(2);
    printf("Median: %.1f\n", findMedian());

    addNum(3);
    printf("Median: %.1f\n", findMedian());

    return 0;
}