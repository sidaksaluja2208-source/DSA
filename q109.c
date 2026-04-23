/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/

#include <stdio.h>
#include <stdlib.h>
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
// Insert into binary tree (for building tree)
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
// 🔹 Search binary tree (main solution
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}
// Level order traversal to print right view
void rightView(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            // Print the rightmost node of the current level
            if (i == levelSize - 1)
                printf("%d ", node->val);
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
    }
}
int main() {
    int N;
    scanf("%d", &N);
    struct TreeNode* root = NULL;

    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        if (val != -1) {
            root = insert(root, val);
        }
    }

    rightView(root);
    return 0;
}
