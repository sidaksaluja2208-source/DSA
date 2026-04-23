/*You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int deque[MAX];
int front = 0, rear = -1;

void push_back(int x) {
    deque[++rear] = x;
}

void pop_back() {
    rear--;
}

void pop_front() {
    front++;
}

int get_front() {
    return deque[front];
}

int empty() {
    return front > rear;
}

int main() {
    int n, k;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter window size k: ");
    scanf("%d", &k);

    int result[n];
    int idx = 0;

    for(int i = 0; i < n; i++) {

        // Remove indices out of current window
        if(!empty() && get_front() <= i - k)
            pop_front();

        // Remove smaller elements from rear
        while(!empty() && nums[deque[rear]] < nums[i])
            pop_back();

        // Insert current index
        push_back(i);

        // Store result once window size is reached
        if(i >= k - 1)
            result[idx++] = nums[get_front()];
    }

    printf("Sliding Window Maximum:\n");
    for(int i = 0; i < idx; i++)
        printf("%d ", result[i]);

    return 0;
}