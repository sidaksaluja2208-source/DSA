/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104*/


#include <stdio.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;

    int curMax = nums[0], maxKadane = nums[0];
    int curMin = nums[0], minKadane = nums[0];

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        totalSum += num;

        // Kadane for maximum subarray
        if (i > 0) {
            curMax = (curMax + num > num) ? curMax + num : num;
            if (curMax > maxKadane) maxKadane = curMax;

            // Kadane for minimum subarray
            curMin = (curMin + num < num) ? curMin + num : num;
            if (curMin < minKadane) minKadane = curMin;
        }
    }

    // If all numbers are negative, maxKadane is the answer
    if (maxKadane < 0) return maxKadane;

    // Otherwise, the answer is max of normal or circular subarray
    int circularMax = totalSum - minKadane;
    return (maxKadane > circularMax) ? maxKadane : circularMax;
}

int main() {
    int nums1[] = {1, -2, 3, -2};
    printf("%d\n", maxSubarraySumCircular(nums1, 4)); // Output: 3

    int nums2[] = {5, -3, 5};
    printf("%d\n", maxSubarraySumCircular(nums2, 3)); // Output: 10

    int nums3[] = {-3, -2, -3};
    printf("%d\n", maxSubarraySumCircular(nums3, 3)); // Output: -2

    return 0;
}
