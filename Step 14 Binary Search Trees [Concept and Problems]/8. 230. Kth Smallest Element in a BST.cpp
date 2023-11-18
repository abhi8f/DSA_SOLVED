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

#define d(x) cout<<#x<<": "<<x<<endl;

class Solution {

public:
    int kthSmallest(TreeNode* root, int &k) {
        if (!root) return -1;

        int leftSide = kthSmallest(root->left, k);
        k--;
        if (k==0) return root->val;
        int rightSide = kthSmallest(root->right, k);

        return max(leftSide, rightSide);
    }
};
