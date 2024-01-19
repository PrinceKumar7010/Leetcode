class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        ListNode * slow=head,*fast=head,*last = NULL;
        //Find the middle node:
        while(fast!=NULL && fast->next!=NULL){
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //This middle node will not be our head:
        TreeNode * treeHead = new TreeNode(slow->val);

        //left subtree: head to last (last is a node behind slow)
        //right subtree: slow->next to NULL

        //last->next should be NULL to break the list:
        //If there was only one node in the list, slow will be at that node and lat will be NULL. So check if last is not NULL
        if(last) last->next = NULL;

        //Left subtree will be head to last, unless there was only one node and slow stayed at head. Then leave left to NULL.
        if(slow != head)
            treeHead->left = sortedListToBST(head);

        //Left subtree will be slow->next to the end of the list, unless there was only one node and slow->next == NULL. Then leave right to NULL.
        if(slow->next != NULL)
            treeHead->right = sortedListToBST(slow->next);
        
        return treeHead;
    }
};