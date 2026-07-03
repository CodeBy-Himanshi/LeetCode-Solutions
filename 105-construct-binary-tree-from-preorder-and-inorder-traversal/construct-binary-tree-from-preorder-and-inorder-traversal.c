/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode* build(int* preorder, int* preIdx, int* inorder, int Start, int End) {
    if (Start > End) {
        return NULL;
    }
    int rootVal = preorder[*preIdx];
    struct TreeNode* root = createNode(rootVal);
    (*preIdx)++;
    int rootInIdx = Start;
    while (rootInIdx <= End && inorder[rootInIdx] != rootVal) {
        rootInIdx++;
    }
    root->left = build(preorder, preIdx, inorder, Start, rootInIdx - 1);
    root->right = build(preorder, preIdx, inorder, rootInIdx + 1, End);

    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIdx = 0;
    return build(preorder, &preIdx, inorder, 0, inorderSize - 1);
}