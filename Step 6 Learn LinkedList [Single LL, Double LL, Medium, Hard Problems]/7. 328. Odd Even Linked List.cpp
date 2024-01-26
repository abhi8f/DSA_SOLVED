class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = even;
        ListNode* cur = head->next->next;
        bool isodd = true;

        while (cur) {
            cout<<cur->val<<endl;
            if (isodd) {
                odd->next = cur;
                odd = cur;
            } else {
                even->next = cur;
                even = cur;
            }
            isodd = !isodd;
            cur = cur->next;
        }
        even->next = NULL;
        odd->next = evenStart;
        // cout<<"hi"<<endl;
        // odd = head;
        // while(odd){
        //     cout<<odd->val<<endl;
        //     odd = odd->next;
        // }
        return head;
    }
};
