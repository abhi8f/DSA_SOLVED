class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) {
            delete head;
            return NULL;
        }

        ListNode* back = head;
        ListNode* front = head;
        while (n--) {
            front = front->next;
        }
        if (front == NULL) {
            return head->next;
        }
        while (front->next) {
            front = front->next;
            back = back->next;
        }
        ListNode* temp = back->next;
        back->next = back->next->next;
        delete temp;
        return head;
    }
};
