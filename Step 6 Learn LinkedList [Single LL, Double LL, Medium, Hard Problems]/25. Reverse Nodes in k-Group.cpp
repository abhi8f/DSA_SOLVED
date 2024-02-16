// #define $(x) cout<<#x<<": "<<x<<endl;
// #define DEBUG
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* dummy = new ListNode();
        ListNode* itr = dummy;

        int n = k;
        ListNode* pre = nullptr;
        ListNode* cur = nullptr;
        ListNode* nex = head;
        ListNode* start = head;

        // auto debug = [&](int line) {
        //     #ifdef DEBUG
        //     $(line - 9);
        //     $(n);
        //     if (itr) {$(itr->val);}
        //     else {$("itr null");}
        //     if (pre) {$(pre->val);}
        //     else {$("pre null");}
        //     if (cur) {$(cur->val);}
        //     else {$("cur null");}
        //     if (nex) {$(nex->val);}
        //     else {$("nex null");}
        //     if (start) {$(start->val);}
        //     else {$("start null");}
        //     cout<<endl<<endl;
        //     #endif
        // };

        while (nex) {
            // debug(__LINE__);
            cur = nex;
            // debug(__LINE__);
            nex = nex->next;
            // debug(__LINE__);
            cur->next = pre;
            // debug(__LINE__);
            pre = cur;
            // debug(__LINE__);
            n--;
            // debug(__LINE__);
            if (n == 0) {
                itr->next = cur;
                // debug(__LINE__);
                itr = start;
                // debug(__LINE__);
                start->next = nullptr;
                // debug(__LINE__);
                start = nex;
                // debug(__LINE__);
                n = k;
                // debug(__LINE__);
            }
            // cout<<endl<<endl;
        }

        // ListNode* p = dummy->next;
        // while(p) {
        //     $(p->val);
        //     p = p->next;
        // }

        if (n != k) {
            start->next = nullptr;
            itr->next = start;
            // debug(__LINE__);

            nex = nullptr;
            // debug(__LINE__);
            while (cur) {
                pre = cur->next;
                // debug(__LINE__);
                cur->next = nex;
                // debug(__LINE__);
                nex = cur;
                // debug(__LINE__);
                cur = pre;
                // debug(__LINE__);
            }
        }


        // itr = dummy->next;
        // while (itr) {
        //     $(itr->val);
        //     itr = itr->next;
        // }
        // cout<<endl<<endl;

        itr = dummy->next;
        delete dummy;
        return itr;

    }
};

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
