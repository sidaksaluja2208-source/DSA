/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}
// Check if two trees are mirror images
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}
// Check if tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
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
    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}