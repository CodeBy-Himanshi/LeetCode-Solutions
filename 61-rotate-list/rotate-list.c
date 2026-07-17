/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL || head->next==NULL)
        return head;
    int size=0,n=0;
    struct ListNode* curr=head;
    while(curr!=NULL){
        size++;
        curr=curr->next;
    }
    curr=head;
    k%=size;
    if(k==0)
        return head; 
    struct ListNode* prev=head;
    while(curr->next!=NULL){
        if(n>=k)
            prev=prev->next;
        curr=curr->next;
        n++;
    }
    curr->next=head;
    head=prev->next;
    prev->next=NULL;
    return head;
}