/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 from leet code 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(2 * sizeof(int));

    int hashSize = 2048;
    int keys[2048];
    int vals[2048];

    for (int i = 0; i < hashSize; i++)
        keys[i] = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        int need = target - nums[i];
        int idx = abs(need) % hashSize;

        while (keys[idx] != INT_MIN) {
            if (keys[idx] == need) {
                result[0] = vals[idx];
                result[1] = i;
                return result;
            }
            idx = (idx + 1) % hashSize;
        }

        int insert = abs(nums[i]) % hashSize;
        while (keys[insert] != INT_MIN)
            insert = (insert + 1) % hashSize;

        keys[insert] = nums[i];
        vals[insert] = i;
    }

    return result;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int* ans = twoSum(nums, size, target, &returnSize);

    printf("[%d, %d]\n", ans[0], ans[1]);

    free(ans);
    return 0;
}
