/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/

#include <stdio.h>
#include <stdlib.h>
// Definition of BST node
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
// Insert into BST (for building tree)
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
// 🔹 Search BST (main solution
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}
int main() {
    int N, val1, val2;
    scanf("%d", &N);
    
    struct TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    scanf("%d %d", &val1, &val2);
    
    struct TreeNode* node1 = searchBST(root, val1);
    struct TreeNode* node2 = searchBST(root, val2);
    
    if (node1 == NULL || node2 == NULL) {
        printf("One or both nodes not found in the BST.\n");
        return 0;
    }
    
    // Find LCA
    struct TreeNode* lca = root;
    while (lca != NULL) {
        if (val1 < lca->val && val2 < lca->val)
            lca = lca->left;
        else if (val1 > lca->val && val2 > lca->val)
            lca = lca->right;
        else
            break; // This is the LCA
    }
    
    printf("%d\n", lca->val);
    
    return 0;
}
