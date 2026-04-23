/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?*/

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
    printf("%s\n", isSymmetric(root) ? "YES" : "NO");
    return 0;
}