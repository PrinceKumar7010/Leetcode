class Solution {
public:
ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);  // Create a dummy node to simplify the code
    dummy->next = head;
    ListNode* current = dummy;

    while (current->next != NULL && current->next->next != NULL) {
        ListNode* first = current->next;
        ListNode* second = current->next->next;

        // Swapping nodes
        first->next = second->next;
        second->next = first;
        current->next = second;

        // Move to the next pair
        current = current->next->next;
    }

    return dummy->next;
}


};