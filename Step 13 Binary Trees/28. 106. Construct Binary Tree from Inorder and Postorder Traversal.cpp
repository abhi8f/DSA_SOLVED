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
    TreeNode *constructTree(int postI, int inI, int inJ, vector<int>& inorder, vector<int>& postorder,  unordered_map<int, int> &inOrderIndexMap) {
        if (inI>inJ) return NULL;

        int inR = inOrderIndexMap[postorder[postI]];

        TreeNode *node = new TreeNode(postorder[postI]);
        node->left = constructTree(postI-1-inJ+inR, inI, inR-1, inorder, postorder, inOrderIndexMap);
        node->right = constructTree(postI-1, inR+1, inJ, inorder, postorder, inOrderIndexMap);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> inOrderIndexMap;
        for(int i=0; i<n; i++) inOrderIndexMap[inorder[i]] = i;

        return constructTree(n-1, 0, n-1, inorder, postorder, inOrderIndexMap);
    }
};
