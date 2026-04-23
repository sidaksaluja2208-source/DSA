/*Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?*/


#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Iterative Inorder Traversal
void inorderTraversal(struct TreeNode* root) {
    struct TreeNode* stack[100];
    int top = -1;
    struct TreeNode* curr = root;

    printf("Inorder Traversal: ");

    while (curr != NULL || top != -1) {

        // Go to leftmost node
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        // Process node
        curr = stack[top--];
        printf("%d ", curr->val);

        // Move to right subtree
        curr = curr->right;
    }

    printf("\n");
}

// Main function
int main() {
    /*
        Example Tree:
              1
               \
                2
               /
              3
    */

    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    inorderTraversal(root);

    return 0;
}