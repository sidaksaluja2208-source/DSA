/*You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-108 <= Node.val <= 108
All the values Node.val are unique.
-108 <= val <= 108
It's guaranteed that val does not exist in the original BST.*/


#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST (Iterative)
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    struct TreeNode* current = root;

    while (1) {
        if (val < current->val) {
            if (current->left == NULL) {
                current->left = createNode(val);
                break;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = createNode(val);
                break;
            }
            current = current->right;
        }
    }

    return root;
}

// Inorder Traversal (Left → Root → Right)
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

// Free memory
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    int n, val;
    struct TreeNode* root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements to insert into BST:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertIntoBST(root, val);
    }

    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");

    // Insert one more value
    printf("Enter value to insert: ");
    scanf("%d", &val);

    root = insertIntoBST(root, val);

    printf("BST after insertion (inorder): ");
    inorder(root);
    printf("\n");

    // Free memory
    freeTree(root);

    return 0;
}