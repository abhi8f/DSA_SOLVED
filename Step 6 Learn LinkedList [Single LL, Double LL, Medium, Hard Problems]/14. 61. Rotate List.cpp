class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* slow = head;
        ListNode* fast = head;

        int len = 0;
        ListNode* lenptr = head;
        while (lenptr) {
            len++;
            lenptr = lenptr->next;
        }
        k = k%len;

        while (k--) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;

        return head;
    }
};
