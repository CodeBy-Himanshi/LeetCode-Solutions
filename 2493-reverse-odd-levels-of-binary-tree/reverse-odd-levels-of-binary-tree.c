/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traverseSymmetric(struct TreeNode* l, struct TreeNode* r, int level) {
    if(l==NULL)
        return;
    if(level%2!=0){
        int temp=l->val;
        l->val=r->val;
        r->val=temp;
    }
    traverseSymmetric(l->left, r->right, level + 1);
    traverseSymmetric(l->right, r->left, level + 1);
}
struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    if(root==NULL)
        return NULL;
    traverseSymmetric(root->left, root->right, 1);
    return root;
}