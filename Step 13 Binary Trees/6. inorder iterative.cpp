class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode *> s;
        while(1) {
            if (root) {
                s.push(root);
                root=root->left;
            }
            else {
                if (s.empty()) break;
                inorder.push_back(s.top()->val);
                root=s.top()->right;
                s.pop();
            }
        }
        return inorder;
    }
};
