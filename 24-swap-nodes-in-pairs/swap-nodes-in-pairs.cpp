class Solution {
public:
ListNode* swapPairs(ListNode* head) {
    ListNode* p = head;

    
        
       
        while (p != NULL && p->next != NULL) {
            ListNode* q = p->next;
            int temp=p->val;
            p->val=q->val;
            q->val=temp;
            p=p->next->next;
            
            
        }
    

    return head;
}

};