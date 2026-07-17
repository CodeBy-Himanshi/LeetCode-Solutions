/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode* curr=&dummy;
    while(curr->next!=NULL && curr->next->next!=NULL){
        if(curr->next->val==curr->next->next->val){
            int n=curr->next->val;
            while(curr->next!=NULL && curr->next->val==n){
                struct ListNode* temp=curr->next;
                curr->next=curr->next->next;
                free(temp);
            }
        } 
        else 
            curr=curr->next;
    }
    return dummy.next;
}