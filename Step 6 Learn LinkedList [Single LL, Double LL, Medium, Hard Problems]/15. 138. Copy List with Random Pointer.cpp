class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        Node* itr = head;
        while (itr) {
            Node* deep = new Node(itr->val);
            deep->next = itr->next;
            itr->next = deep;
            itr = deep->next;
        }
        itr = head;
        while (itr) {
            Node* deepItr = itr->next;
            if (itr->random != nullptr) {
                deepItr->random = itr->random->next;
            }
            itr = itr->next->next;
        }
        itr = head;
        Node* deepItr = new Node(-1);
        head = deepItr;
        while (itr) {
            deepItr->next= itr->next;
            deepItr = deepItr->next;
            itr->next = itr->next->next;
            itr = itr->next;
        }
        deepItr = head;
        head = head->next;
        delete deepItr;
        return head;
    }
};
