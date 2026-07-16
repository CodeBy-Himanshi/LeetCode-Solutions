/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    struct ListNode* first=head;
    struct ListNode* second=head->next;
    struct ListNode* prev=NULL;
    head=second;
    while(first!=NULL && first->next!=NULL){
        second=first->next;
        struct ListNode* temp=second->next;
        second->next=first;
        first->next=temp;
        if(prev!=NULL)
            prev->next=second;
        prev=first;
        first=temp;
    }
    return head;
}