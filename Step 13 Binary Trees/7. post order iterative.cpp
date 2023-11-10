class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode *> s;
        while(1) {
            if (root) {
                s.push(root);
                root=root->left;
            }
            else {
                if (s.empty()) break;
                TreeNode *temp = s.top()->right;
                if (temp==NULL) {
                    temp = s.top();
                    s.pop();
                    postorder.push_back(temp->val);
                    while(s.empty()==false && s.top()->right==temp) {
                        temp=s.top();
                        s.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else root = temp;
            }
        }
        return postorder;
    }
};
