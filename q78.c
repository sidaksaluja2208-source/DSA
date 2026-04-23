/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int value;
    int freq;
} Node;

int compare(const void *a, const void *b)
{
    Node *x = (Node *)a;
    Node *y = (Node *)b;

    return y->freq - x->freq;   // descending order
}

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);

    printf("Enter k: ");
    scanf("%d",&k);

    Node freq[MAX];
    int unique = 0;

    // Frequency counting
    for(int i=0;i<n;i++)
    {
        int found = 0;

        for(int j=0;j<unique;j++)
        {
            if(freq[j].value == nums[i])
            {
                freq[j].freq++;
                found = 1;
                break;
            }
        }

        if(!found)
        {
            freq[unique].value = nums[i];
            freq[unique].freq = 1;
            unique++;
        }
    }

    // Sort based on frequency
    qsort(freq, unique, sizeof(Node), compare);

    printf("Top %d frequent elements:\n", k);

    for(int i=0;i<k;i++)
        printf("%d ", freq[i].value);

    return 0;
}