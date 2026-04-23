/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/

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
// Level order traversal
void zigzagLevelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    int level = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;
        int temp[size];
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            temp[i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        if (level % 2 == 1) {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", temp[i]);
        } else {
            for (int i = 0; i < size; i++)
                printf("%d ", temp[i]);
        }
        level++;
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
    
    zigzagLevelOrder(root); // Call zigzag level order traversal function
    
    return 0;
}
