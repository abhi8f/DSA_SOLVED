class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(q.empty()==false) {
            vector<int> level;
            int n = q.size();
            for(int i=0; i<n; i++) {
                TreeNode *cur = q.front();
                q.pop();
                level.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
