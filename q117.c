/*roblem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/

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
// Build tree from inorder and postorder
struct TreeNode* buildTree(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;
    struct TreeNode* node = createNode(postorder[*postIndex]);
    (*postIndex)--;
    if (inStart == inEnd) return node;
    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (inorder[inIndex] == node->val) break;
    }
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);
    return node;
}
// Preorder traversal
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int N;
    scanf("%d", &N);
    int* inorder = (int*)malloc(N * sizeof(int));
    int* postorder = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }
    int postIndex = N - 1;
    struct TreeNode* root = buildTree(inorder, postorder, 0, N - 1, &postIndex);
    preorder(root);
    free(inorder);
    free(postorder);
    return 0;
}
