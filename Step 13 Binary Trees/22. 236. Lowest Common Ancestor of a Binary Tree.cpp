class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root==p || root==q) return root;

        TreeNode *leftSide = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightSide = lowestCommonAncestor(root->right, p, q);

        if (!leftSide) return rightSide;
        if (!rightSide) return leftSide;
        return root;
    }
};
