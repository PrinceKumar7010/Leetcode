/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev= dummy;
        ListNode* cur= head;
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* node = head;
        int cnt=0;
        while(node!=nullptr){
            cnt++;
            node = node->next;
        }
        k%=cnt;
        for(int i=0;i<k;i++){
            while(cur->next!=nullptr){
                prev =prev->next;
                cur = cur->next;
            }
            cur->next=dummy->next;
            prev->next = nullptr;
            dummy->next = cur;
            prev = dummy;
        }
        return dummy->next ;
    }
};