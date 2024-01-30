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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        ListNode* itr = dummy;

        while (head) {
            if (head->val == val) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            } else {
                itr->next = head;
                itr = head;
                head = head->next;
            }
        }
        itr->next = nullptr;
        itr = dummy->next;
        delete dummy;
        return itr;
    }
};
