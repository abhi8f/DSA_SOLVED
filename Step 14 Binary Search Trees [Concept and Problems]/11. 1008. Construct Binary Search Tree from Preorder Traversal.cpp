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
    TreeNode *construct(int &i, int mx, vector<int> &preorder) {
        if (i>=preorder.size() || preorder[i]>mx) {
            return NULL;
        }
        TreeNode *cur = new TreeNode(preorder[i]);
        i++;
        cur->left = construct(i, cur->val, preorder);
        cur->right = construct(i, mx, preorder);
        return cur;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return construct(i, INT_MAX, preorder);
    }
};
