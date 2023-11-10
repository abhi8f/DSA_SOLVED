class Solution {
private:
    void preorderTraversal(TreeNode *node, vector<int> &preorder) {
        if (node==NULL) return;
        preorder.push_back(node->val);
        preorderTraversal(node->left, preorder);
        preorderTraversal(node->right, preorder);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> cur;
        preorderTraversal(root, cur);
        return cur;
    }
};
