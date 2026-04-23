/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/


#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefix[n + 1];
    prefix[0] = 0;

    // Compute prefix sums
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    // Sort prefix sums
    qsort(prefix, n + 1, sizeof(long long), compare);

    long long count = 0;

    // Count equal prefix sums using grouping
    long long freq = 1;
    for (int i = 1; i <= n; i++) {
        if (prefix[i] == prefix[i - 1]) {
            freq++;
        } else {
            count += (freq * (freq - 1)) / 2;
            freq = 1;
        }
    }

    // Final group
    count += (freq * (freq - 1)) / 2;

    printf("%lld\n", count);

    return 0;
}