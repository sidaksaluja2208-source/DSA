/* 
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays 
and you may return the result in any order.
*/

#include <stdio.h>

int main() {
    int n1, n2;

    // Input size of nums1
    scanf("%d", &n1);
    int nums1[n1];
    for (int i = 0; i < n1; i++)
        scanf("%d", &nums1[i]);

    // Input size of nums2
    scanf("%d", &n2);
    int nums2[n2];
    for (int i = 0; i < n2; i++)
        scanf("%d", &nums2[i]);

    // Frequency arrays for values 0–1000
    int freq1[1001] = {0};
    int freq2[1001] = {0};

    // Count frequencies in nums1
    for (int i = 0; i < n1; i++)
        freq1[nums1[i]]++;

    // Count frequencies in nums2
    for (int j = 0; j < n2; j++)
        freq2[nums2[j]]++;

    // Print intersection
    for (int k = 0; k <= 1000; k++) {
        int minCount = (freq1[k] < freq2[k]) ? freq1[k] : freq2[k];
        
        while (minCount--) {
            printf("%d ", k);
        }
    }

    return 0;
}
