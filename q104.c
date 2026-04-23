/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.*/

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

    struct TreeNode* leftSearch = searchBST(root->left, val);
    if (leftSearch != NULL)
        return leftSearch;

    return searchBST(root->right, val);
}
// Find LCA in binary tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;

    if (root->val == p->val || root->val == q->val)
        return root;

    struct TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA != NULL && rightLCA != NULL)
        return root; // This is the split point, so it's the LCA

    return (leftLCA != NULL) ? leftLCA : rightLCA;
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
    int pVal, qVal;
    scanf("%d %d", &pVal, &qVal);
    struct TreeNode* p = searchBST(root, pVal);
    struct TreeNode* q = searchBST(root, qVal);
    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        printf("%d\n", lca->val);
    } else {
        printf("LCA not found.\n");
    }
    return 0;
}
