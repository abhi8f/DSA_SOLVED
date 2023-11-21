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
    void preorder(TreeNode* root, TreeNode *&pre, TreeNode *&mistake1, TreeNode *&mistake2) {
        if(!root) {
            return;
        }

        preorder(root->left, pre, mistake1, mistake2);

        if(mistake1 == nullptr && pre && pre->val >= root->val) {
            mistake1 = pre;
        }
        if(mistake1 != nullptr && pre && pre->val >= root->val) {
            mistake2 = root;
        }

        pre = root;
        preorder(root->right, pre, mistake1, mistake2);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *pre=NULL, *mistake1=NULL, *mistake2=NULL;
        preorder(root, pre, mistake1, mistake2);
        swap(mistake1->val, mistake2->val);
    }
};
