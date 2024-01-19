class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int prev = 0;

        while(head){
            // Standing at the current node just if we have next node value repeating we will skip nodes while it is equal to the current node value;
            if(head->next && head->next->val == head->val){
                int val = head->val;
                while(head && head->val == val) head = head->next;
            }else{
                dummy->next= head;
                dummy = dummy->next;
                head = head->next;
            }
        }

        dummy->next = NULL;

        return temp->next;
    }
};