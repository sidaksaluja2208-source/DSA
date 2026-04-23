/*You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107*/

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

// 🔹 Search BST (main solution)
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

// Preorder traversal to print subtree
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct TreeNode* root = NULL;

    // Build tree: [4,2,7,1,3]
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);

    int val;
    printf("Enter value to search: ");
    scanf("%d", &val);

    struct TreeNode* result = searchBST(root, val);

    if (result == NULL) {
        printf("[]\n");  // Not found
    } else {
        printf("Subtree rooted at %d: ", val);
        preorder(result);  // print subtree
        printf("\n");
    }

    return 0;
}