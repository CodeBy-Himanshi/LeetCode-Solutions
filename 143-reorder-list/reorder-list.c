/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if(head==NULL || head->next ==NULL || head->next->next==NULL)
        return;
    struct ListNode* curr=head;
    int n=0;
    while(curr!=NULL){
        n++;
        curr=curr->next;
    }
    curr=head;
    struct ListNode** stack=(struct ListNode**)malloc(n*sizeof(struct ListNode*));
    for(int i=0;i<n;i++){
        stack[i]=curr;
        curr=curr->next;
    }
    int lb=0, ub=n-1;
    while(lb<ub){
        stack[lb]->next=stack[ub];
        lb++;
        if(lb==ub)
            break;
        stack[ub]->next=stack[lb];
        ub--;
    }
    stack[lb]->next=NULL;
    free(stack);
}