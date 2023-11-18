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
class Solution {
private: 
    bool isValidBSTHelper(TreeNode *root, long &pre) {
        if (!root) return true;

        if (!isValidBSTHelper(root->left, pre)) return false;
        if (pre >= root->val) return false;
        pre = root->val;
        return isValidBSTHelper(root->right, pre);

    }
public:
    bool isValidBST(TreeNode* root) {
        long pre = LONG_MIN;
        return isValidBSTHelper(root, pre);
    }
};
