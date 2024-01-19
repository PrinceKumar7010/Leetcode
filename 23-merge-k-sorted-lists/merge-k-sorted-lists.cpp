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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                temp->next=a;
                a=a->next;
                temp=temp->next;
            }
            else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
            }
        }

        while(a!=NULL){
            temp->next=a;
            a=a->next;
            temp=temp->next;
        }
        while(b!=NULL){
            temp->next=b;
            b=b->next;
            temp=temp->next;
        }

        return dummy->next;
    }
    ListNode* f(vector<ListNode*>&lists, int left, int right){
        if(left>=right) return lists[left];

        int mid = (left+right)/2;
        ListNode* a = f(lists,left, mid);
        ListNode* b = f(lists,mid+1,right);
        return merge(a,b);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return f(lists,0,lists.size()-1);
    }
};