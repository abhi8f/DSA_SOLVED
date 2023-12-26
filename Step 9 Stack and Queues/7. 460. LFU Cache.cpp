struct Node {
    int key;
    int val;
    int freq = 0;
    Node* pre = NULL;
    Node* next = NULL;
    Node(int keyInput, int valInput) : key(keyInput), val(valInput) {}
};

class List {
   public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int count = 0;
    List() {
        head->next = tail;
        tail->pre = head;
    }

    void linkNextToHead(Node* node) {
        node->next = head->next;
        head->next->pre = node;
        node->pre = head;
        head->next = node;
        count++;
    }

    void unlink(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        count--;
    }
};

class LFUCache {
    int step = 0;
    int cap;
    int count = 0;
    int minFreq = 0;
    map<int, Node*> keyNode;
    map<int, List*> freqList;
public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    void updatePos(Node* node) {
        int& freq = node->freq;
        List* lruc = freqList.find(freq)->second;
        lruc->unlink(node);

        if (lruc->count == 0 && minFreq == freq) {
            minFreq = freq + 1;
        }
        freq++;
        List* lrucNext;
        auto searchLrucNext = freqList.find(freq);
        if (searchLrucNext == freqList.end()) {
            lrucNext = new List();
            freqList.emplace(freq, lrucNext);
        } else {
            lrucNext = searchLrucNext->second;
        }

        lrucNext->linkNextToHead(node);
    }

    int get(int key) {
        auto search = keyNode.find(key);
        if (search == keyNode.end()) return -1;
        Node* node = search->second;
        updatePos(node);
        return node->val;
    }

    void put(int key, int value) {
        auto search = keyNode.find(key);
        if (search != keyNode.end()) {
            Node* node = search->second;
            updatePos(node);
            node->val = value;
            return;
        }

        if (count == cap) {
            count--;
            List* lruc = freqList.find(minFreq)->second;
            Node* lru = lruc->tail->pre;
            lruc->unlink(lru);
            keyNode.erase(lru->key);
            delete lru;
        }
        count++;
        Node* node = new Node(key, value);
        keyNode.emplace(key, node);
        List* lruc0;
        auto searchLruc0 = freqList.find(0);
        if (searchLruc0 == freqList.end()) {
            lruc0 = new List();
            freqList.emplace(0, lruc0);
        } else {
            lruc0 = searchLruc0->second;
        }
        lruc0->linkNextToHead(node);
        minFreq = 0;
        return;
    }
};
