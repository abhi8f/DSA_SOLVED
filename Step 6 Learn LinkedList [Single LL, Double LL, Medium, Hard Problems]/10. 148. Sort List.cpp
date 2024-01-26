class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        ListNode* temp = new ListNode(-1);
        ListNode* itr = temp;

        while (left && right) {
            if (left->val < right->val) {
                itr->next = left;
                itr = left;
                left = left->next;
            } else {
                itr->next = right;
                itr = right;
                right = right->next;
            }
        }
        if (left) {
            itr->next = left;
        } else if (right) {
            itr->next = right;
        }
        itr = temp->next;
        delete temp;
        return itr;
    }
};
