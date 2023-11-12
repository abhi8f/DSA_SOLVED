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
    TreeNode *constructTree(int preI, int inI, int inJ, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &inOrderIndexMap) {
        if (inI>inJ) return NULL;

        int inR = inOrderIndexMap[preorder[preI]];

        TreeNode *node = new TreeNode(preorder[preI]);
        node->left = constructTree(preI+1, inI, inR-1, preorder, inorder, inOrderIndexMap);
        node->right = constructTree(preI+1+inR-inI, inR+1, inJ, preorder, inorder, inOrderIndexMap);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inOrderIndexMap;
        for(int i=0; i<n; i++) inOrderIndexMap[inorder[i]] = i;

        return constructTree(0, 0, n-1, preorder, inorder, inOrderIndexMap);
    }
};
