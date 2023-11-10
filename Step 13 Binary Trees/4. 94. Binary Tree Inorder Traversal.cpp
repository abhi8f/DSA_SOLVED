class Solution {
private:
    void inorderTraversal(TreeNode *node, vector<int> &inorder) {
        if (node==NULL) return;
        inorderTraversal(node->left, inorder);
        inorder.push_back(node->val);
        inorderTraversal(node->right, inorder);
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> cur;
        inorderTraversal(root, cur);
        return cur;
    }
};
