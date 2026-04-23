/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.*/

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
