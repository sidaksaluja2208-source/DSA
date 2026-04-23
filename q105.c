/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

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

struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);

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

int main() {
    int N;
    scanf("%d", &N);
    
    struct TreeNode* root = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        if (val != -1) {
            root = insertNode(root, val);
        }
    }
    
    // Call vertical order traversal function here (not implemented in this snippet)
    
    return 0;
}
