/*You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val == 0*/

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
// Build tree from level order
struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0) return NULL;
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    for (int i = 1; i < n; i++) {
        struct TreeNode* parent = queue[front++];
        parent->left = createNode(arr[i]);
        queue[rear++] = parent->left;
        if (++i < n) {
            parent->right = createNode(arr[i]);
            queue[rear++] = parent->right;
        }
    }
    free(queue);
    return root;
}
// Count cameras
int countCameras(struct TreeNode* root, int* cameras) {
    if (root == NULL) return 0;
    int left = countCameras(root->left, cameras);
    int right = countCameras(root->right, cameras);
    if (left == 0 || right == 0) {
        (*cameras)++;
        return 1;
    }
    if (left == 1 || right == 1) {
        return 2;
    }
    return 0;
}
int minCameraCover(struct TreeNode* root) {
    int cameras = 0;
    if (countCameras(root, &cameras) == 0) {
        cameras++;
    }
    return cameras;
}
int main() {
    int N;
    scanf("%d", &N);
    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    struct TreeNode* root = buildTree(arr, N);
    printf("%d\n", minCameraCover(root));
    free(arr);
    return 0;
}
