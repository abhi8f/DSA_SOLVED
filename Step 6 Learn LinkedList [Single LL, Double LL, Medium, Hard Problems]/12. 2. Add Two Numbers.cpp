class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev = NULL;
        ListNode* head = l1;

        while (l1 && l2) {
            int num = l1->val + l2->val + carry;
            int digit = num % 10;
            carry = num/10;
            l1->val = digit;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;

        }
        while (l1) {
            int num = l1->val + carry;
            int digit = num % 10;
            carry = num/10;
            l1->val = digit;
            prev= l1;
            l1 = l1->next;
        }
        prev->next = l2;
        while (l2) {
            int num = l2->val + carry;
            int digit = num % 10;
            carry = num/10;
            l2->val = digit;
            prev = l2;
            l2 = l2->next;
        }

        while (carry) {
            int digit = carry%10;
            carry /= 10;
            prev->next = new ListNode(digit);
            prev = prev->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* itr = dummy;

        while ((l1 != nullptr) || (l2 != nullptr) || (carry != 0)) {
            int l1v = 0;
            if (l1 != nullptr) {
                l1v = l1->val;
                l1 = l1->next;
            }
            int l2v = 0;
            if (l2 != nullptr) {
                l2v = l2->val;
                l2 = l2->next;
            }

            int num = l1v + l2v + carry;
            int digit = num % 10;
            carry = num/10;
            itr->next = new ListNode(digit);
            itr = itr->next;
        }
        itr = dummy->next;
        delete dummy;
        return itr;
    }
};
