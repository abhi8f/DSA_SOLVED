class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* pre = NULL;
        ListNode* cur = slow;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        while (head != slow) {
            if (head->val != pre->val) return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};
