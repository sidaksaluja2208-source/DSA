/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000*/

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
// 🔹 Search binary tree (main solution)
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}
// Level order traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;

    // Implement level order traversal using a queue (not implemented in this snippet)
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
    
    levelOrder(root); // Call level order traversal function
    
    return 0;
}
