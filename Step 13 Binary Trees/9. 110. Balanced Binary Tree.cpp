class Solution {
private:
    int isBalancedHelper(TreeNode *root) {
        if (!root) return 0;
        int leftHeight = isBalancedHelper(root->left);
        if (leftHeight==-1) return -1;
        int rightHeight = isBalancedHelper(root->right);
        if (rightHeight==-1) return -1;

        if (abs(leftHeight-rightHeight)<=1) return 1 + max(leftHeight, rightHeight);
        return -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (isBalancedHelper(root)==-1) return false;
        return true;
    }
};
