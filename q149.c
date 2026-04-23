/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000   // size of hash table

// Hash node
struct Node {
    int sum;
    int index;
    struct Node* next;
};

// Hash table
struct Node* hashTable[MAX];

// Hash function
int hash(int sum) {
    return abs(sum) % MAX;
}

// Insert into hash table
void insert(int sum, int index) {
    int h = hash(sum);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

// Search in hash table
int search(int sum) {
    int h = hash(sum);
    struct Node* temp = hashTable[h];
    while (temp != NULL) {
        if (temp->sum == sum)
            return temp->index;
        temp = temp->next;
    }
    return -1;
}

// Main function
int longestZeroSumSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if (sum == 0)
            maxLen = i + 1;

        // Case 2: sum seen before
        int prevIndex = search(sum);
        if (prevIndex != -1) {
            int len = i - prevIndex;
            if (len > maxLen)
                maxLen = len;
        } else {
            insert(sum, i);
        }
    }
    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", longestZeroSumSubarray(arr, n));

    return 0;
}