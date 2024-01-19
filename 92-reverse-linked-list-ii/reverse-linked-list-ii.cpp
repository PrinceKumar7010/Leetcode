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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node=head;
        if(!head || left==right)return head;
        stack<ListNode*>st;
        bool flag=0;
        int count=1;
        ListNode* prev=NULL;
        while(node){

            if(count==left)flag=1;
            if(flag){
                st.push(node);
                if(count==right)break;
            }
            
            if(!flag)prev=node;
            node=node->next;
            count++;
        }
       if(node) node=node->next;
       
       if(st.empty())return head;
        while(!st.empty()){
            if(prev){prev->next=st.top();
            prev=prev->next;
            }
            else {ListNode* temp=st.top();
            head=temp;
            prev=temp;
        
            }
            st.pop();

        }
        
           prev->next=node;
            
      
        return head;
    }
};