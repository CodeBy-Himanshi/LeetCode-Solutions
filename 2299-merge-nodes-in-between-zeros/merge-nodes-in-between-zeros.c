/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode dummy;
    dummy.val=0;
    dummy.next=NULL;
    struct ListNode* current=&dummy;
    struct ListNode* curr=head->next;
    int sum=0;
    while(curr!=NULL){
        if(curr->val!=0)
            sum+=curr->val;
        else{
            struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val=sum;
            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
            sum=0;
        }
        curr=curr->next;
    }
    return dummy.next;
}