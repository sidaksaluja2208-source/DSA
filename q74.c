/*You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8

Example 2:

Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

Output: [null, 7, 7, 7, 8]

Explanation:

KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8
 

Constraints:

0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.*/

#include <stdio.h>

#define MAX 10005

int heap[MAX];
int size = 0;
int k;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i){
    while(i > 0){
        int parent = (i - 1) / 2;
        if(heap[parent] > heap[i]){
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(int i){
    while(1){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != i){
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

void insert(int val){
    heap[size] = val;
    heapifyUp(size);
    size++;
}

void removeMin(){
    heap[0] = heap[size-1];
    size--;
    heapifyDown(0);
}

int add(int val){
    insert(val);

    if(size > k){
        removeMin();
    }

    return heap[0]; 
}

void KthLargest(int K, int nums[], int n){
    k = K;
    size = 0;

    for(int i = 0; i < n; i++){
        add(nums[i]);
    }
}

int main(){

    int nums[] = {4,5,8,2};
    int n = 4;

    KthLargest(3, nums, n);

    printf("%d\n", add(3));
    printf("%d\n", add(5));
    printf("%d\n", add(10));
    printf("%d\n", add(9));
    printf("%d\n", add(4));

    return 0;
}