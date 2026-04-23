/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/

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
// Flatten the tree
void flatten(struct TreeNode* root) {
    if (root == NULL) return;
    flatten(root->left);
    flatten(root->right);
    struct TreeNode* temp = root->right;
    root->right = root->left;
    root->left = NULL;
    struct TreeNode* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    current->right = temp;
}
// Preorder traversal to print flattened tree
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
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
    flatten(root);
    preorder(root);
    return 0;
}

