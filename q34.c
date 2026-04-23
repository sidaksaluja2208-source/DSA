/*Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.*/

#include <stdio.h>
#include <limits.h>

int maxSubArray(int nums[], int n) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < n; i++) {
        // Either add nums[i] or start new subarray
        if (currentSum + nums[i] < nums[i])
            currentSum = nums[i];
        else
            currentSum += nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("%d\n", maxSubArray(nums, n));
    return 0;
}
