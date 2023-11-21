/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private: 
    stack<TreeNode *> nodeStack;
    bool asc;
    void pushAllLeft(TreeNode *node) {
        while(node) {
            nodeStack.push(node);
            node = asc ? node->left : node->right;
        }
    }
public:
    BSTIterator(TreeNode* root, bool asc) {
        this->asc = asc;
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode *node = nodeStack.top();
        nodeStack.pop();

        int ans = node->val;

        pushAllLeft(asc ? node->right : node->left);
        return ans;
    }
    
    bool hasNext() {
        return !nodeStack.empty();
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        BSTIterator a(root, true);
        BSTIterator d(root, false);

        int iv = a.next(), jv = d.next(), curK;

        while (iv<jv) {
            curK = iv + jv;
            if (curK == k) return true;
            if (curK < k) iv = a.next();
            else jv = d.next();
        }
        return false;
    }
};
