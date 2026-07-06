/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize=0;
    if(root==NULL)
        return NULL;
    int* result=(int *)malloc(100*sizeof(int));
    struct TreeNode** queue=(struct TreeNode**)malloc(100*sizeof(struct TreeNode*));
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        int ls=rear-front;
        for(int i=0;i<ls;i++){
            struct TreeNode* curr = queue[front++];
            if (i == ls - 1)
                result[(*returnSize)++] = curr->val;
            if (curr->left != NULL)
                queue[rear++] = curr->left;
            if (curr->right != NULL)
                queue[rear++] = curr->right;
        }
    }
    free(queue);
    return result;
}