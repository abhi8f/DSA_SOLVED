class Solution {
private:
    int getDiameter(TreeNode *root, int &maxDiameter) {
        if (!root) return 0;
        int leftHeight = getDiameter(root->left, maxDiameter);
        int rightHeight = getDiameter(root->right, maxDiameter);
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        getDiameter(root, ans);
        return ans;
    }
};
