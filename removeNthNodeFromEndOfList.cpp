//problem statement(link) : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

//using 2-pointers method
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* c=head;
    ListNode* p=c;
    ListNode* next=head;
    n=n-1;
    while(n-- && next->next!=NULL){
        next=next->next;
    }
    while(next->next!=NULL){
        p=c;
        c=c->next;
        next=next->next;
    }
    if(c==head){
        p=c->next;
        c->next=NULL;
        return p;
    }
    p->next=c->next;
    c->next=NULL;
        
    return head;
}
