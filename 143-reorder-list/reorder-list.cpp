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
    void reorderList(ListNode* head) {
        // Edge cases where nothing happens
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }

        // Insert all list elements into stack
        stack<ListNode*> st{};
        ListNode* p = head;
        while (p != nullptr) {
            st.push(p);
            p = p->next;
        }

        // Interleave the list with itself (main algo)
        p = head;
        set<ListNode*> used{};
        while (!used.contains(p)) {
            // Insert into used set
            used.insert(p);

            // Get the top of the stack and pop it, this should be the element closest to the end
            ListNode* top = st.top();   st.pop();

            // Do our swap operation
            top->next = p->next;    // Top->next is now the p->next of the original list
            p->next = top;          // p->next should now be the top (interleaving)
            p = p->next->next;      // p is now the original next from the original list (equivalent to top->next which was set to p->next)
        }
        p->next = nullptr;          // Terminate our list (p should be somewhere near L sub n/2)
        // If we don't do this leetcode will attempt to deconstruct our list once finished and cause unsolvable problems when deallocating
    }
};