class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* next = node->next;
        node->next = node->next->next;
        delete next;
    }
};

Node* deleteNode(Node *head,int x)
{
    if (x == 1) {
        Node* ans = head->next;
        delete head;
        return ans;
    }
    Node* pre = head;
    Node* cur = head->next;
    int count = 2;
    while (cur != NULL) {
        if (count == x) {
            pre->next = cur->next;
            delete cur;
            return head;
        }
        pre = cur;
        cur = cur->next;
        count++;
    }
    return head;
}
