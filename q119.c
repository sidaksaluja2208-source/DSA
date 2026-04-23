/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.*/

#include<stdio.h>
#include<stdlib.h>
// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
// Build tree from level order
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0) return NULL;
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    for (int i = 1; i < n; i++) {
        struct TreeNode* parent = queue[front++];
        parent->left = createNode(arr[i]);
        queue[rear++] = parent->left;
        if (++i < n) {
            parent->right = createNode(arr[i]);
            queue[rear++] = parent->right;
        }
    }
    free(queue);
    return root;
}
// Check Min-Heap property
int isMinHeap(struct TreeNode* root) {
    if (root == NULL) return 1;
    if (root->left && root->val > root->left->val) return 0;
    if (root->right && root->val > root->right->val) return 0;
    return isMinHeap(root->left) && isMinHeap(root->right);
}
int main() {
    int N;
    scanf("%d", &N);
    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    struct TreeNode* root = buildTree(arr, N);
    if (isMinHeap(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    free(arr);
    return 0;
}
