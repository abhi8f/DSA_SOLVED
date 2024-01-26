class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) {
            delete head;
            return NULL;
        }
        if (!head->next->next) {
            delete head->next;
            head->next = NULL;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};
