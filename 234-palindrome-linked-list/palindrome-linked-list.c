/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
        return true;
    struct ListNode* slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode* prev=NULL,*curr=slow;
    while(curr!=NULL){
        struct ListNode* nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    struct ListNode* p1=head,*p2=prev;
    while(p2!=NULL){
        if(p1->val!=p2->val)
            return false;
        p1=p1->next;
        p2=p2->next;
    }
    return true;
}