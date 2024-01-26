class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0;
        ListNode* itr1 = headA;
        while (itr1) {
            l1++;
            itr1 = itr1->next;
        }
        int l2 = 0;
        ListNode* itr2 = headB;
        while (itr2) {
            l2++;
            itr2 = itr2->next;
        }

        while (l1 > l2) {
            l1--;
            headA = headA->next;
        }
        while(l2 > l1) {
            l2--;
            headB = headB->next;
        }
        while (headA){
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 || t2) {
            if (!t1) t1 = headB;
            else if (!t2) t2 = headA;

            if (t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }

        return NULL;
    }
};
