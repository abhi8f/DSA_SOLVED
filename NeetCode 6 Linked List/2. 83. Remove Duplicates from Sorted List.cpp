class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* once = head;
        ListNode* itr = head->next;

        while(itr) {
            if (once->val != itr->val) {
                once = once->next = itr;
                itr = itr->next;
            } else {
                ListNode* temp = itr;
                itr = itr->next;
                delete temp;
            }
        }
        once->next = nullptr;
        return head;
    }
};
