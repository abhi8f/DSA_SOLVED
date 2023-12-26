struct Node {
    int key;
    int val;
    Node* pre = NULL;
    Node* next = NULL;
    Node(int keyInput, int valInput) : key(keyInput), val(valInput) {}
};

class LRUCache {
    unordered_map<int, Node*> keyNode;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int count = 0;
    int cap;

   public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre = head;
    }

    void linkNextToHead(Node* node) {
        node->next = head->next;
        head->next->pre = node;
        node->pre = head;
        head->next = node;
    }

    void unlink(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    int get(int key) {
        auto search = keyNode.find(key);
        if (search == keyNode.end()) return -1;
        unlink(search->second);
        linkNextToHead(search->second);
        return search->second->val;
    }

    void put(int key, int value) {
        auto search = keyNode.find(key);

        if (search != keyNode.end()) {
            unlink(search->second);
            linkNextToHead(search->second);
            search->second->val = value;
            return;
        }

        if (count == cap) {
            Node* lru = tail->pre;
            unlink(lru);
            keyNode.erase(lru->key);
            delete lru;
            count--;
        }



        Node* node = new Node(key, value);
        keyNode.emplace(key, node);
        linkNextToHead(node);
        count++;
        return;
    }
};
