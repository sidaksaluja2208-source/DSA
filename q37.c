/**/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int bestL = left, bestR = right;
    int bestSum = INT_MAX;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(bestSum)) {
            bestSum = sum;
            bestL = left;
            bestR = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", arr[bestL], arr[bestR]);

    return 0;
}
