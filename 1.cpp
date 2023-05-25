#include <bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
const int ALPHABET_SIZE = 26;
class Trie {
   private:
    // trie node
    struct TrieNode {
        struct TrieNode *children[ALPHABET_SIZE];

        // isEndOfWord is true if the node represents
        // end of a word
        bool isEndOfWord;
    };
    struct TrieNode *root = newNode();

    // Returns new trie node (initialized to NULLs)
    struct TrieNode *newNode(void) {
        struct TrieNode *pNode = new TrieNode;

        pNode->isEndOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;

        return pNode;
    }
   public:

    /** Initialize your data structure here. */
    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = newNode();

            pCrawl = pCrawl->children[index];
        }

        // mark last node as leaf
        pCrawl->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl->isEndOfWord);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i<prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return true;
    }
};

int main() {
    Trie t;

    return 0;
}