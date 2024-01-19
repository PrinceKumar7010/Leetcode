/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    void insertTail(Node* &head,Node* &tail,int val){
        Node* newnode = new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        //step1 : create Linked List
        Node* temp = head;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        while(temp!=NULL){
            insertTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        
        //step2: add node beetween originalNode
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            Node* next1 = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next1;
            
            Node* next2 = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next2;
        }
        
        //step3 : copy random pointer
        temp=head;
        while(temp!=NULL){
            if(temp->next !=NULL){
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp=temp->next->next;
        }
        
        //step4 : revert thr stage 2
        originalNode = head;
        cloneNode = cloneHead;
         while(originalNode!=NULL && cloneNode!=NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode!=NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        
        //step5 : return ans
        return cloneHead;
    }
};