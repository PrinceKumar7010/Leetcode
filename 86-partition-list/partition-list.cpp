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
    ListNode* partition(ListNode* head, int x) {
        vector<int> less;
        int i = 0 ;
        vector<int> more;
        int j = 0;
        ListNode* temp = head ;
        while(temp!=NULL){
            if(temp->val<x){
                less.push_back(temp->val);
                i++;
            }
            else{
                more.push_back(temp->val);
                j++;
            }
            temp = temp->next ;
        }
        temp = head;
        int count = 0;
        while(count<i){
            temp->val = less[count];
            count ++ ;
            temp = temp->next ;
        }

        count = 0;

        while(count<j){
            temp->val = more[count];
            count ++ ;
            temp = temp->next ;
        }
        return(head);

    }
};