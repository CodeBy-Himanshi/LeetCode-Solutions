/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createnode(int val){
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}
struct TreeNode* build(int* postorder, int* postIdx, int* inorder, int Start, int End) {
    if (Start > End) {
        return NULL;
    }
    int rootVal = postorder[*postIdx];
    struct TreeNode* root = createnode(rootVal);
    (*postIdx)--;
    int rootInIdx = Start;
    while (rootInIdx <= End && inorder[rootInIdx] != rootVal) {
        rootInIdx++;
    }
    root->right = build(postorder, postIdx, inorder, rootInIdx + 1, End);
    root->left = build(postorder, postIdx, inorder, Start, rootInIdx - 1);
    return root;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIdx = postorderSize-1;
    return build(postorder, &postIdx, inorder, 0, inorderSize - 1);
}