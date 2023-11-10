class Solution {
private:
    bool isSymmetricHelper(TreeNode *node1, TreeNode *node2) {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;
        if (node1->val != node2->val) return false;
        return isSymmetricHelper(node1->left, node2->right) && isSymmetricHelper(node1->right, node2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetricHelper(root->left, root->right);
    }
};
