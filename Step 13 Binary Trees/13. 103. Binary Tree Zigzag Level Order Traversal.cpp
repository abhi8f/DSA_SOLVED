class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        bool zigzag = false;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            int s = Q.size();
            vector<int> level(s);
            for(int i=0; i<s; i++) {
                TreeNode *cur = Q.front();
                Q.pop();
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);

                if (zigzag) level[s-i-1] = cur->val;
                else level[i] = cur->val;
            }
            zigzag = !zigzag;
            ans.push_back(level);
        }
        return ans;
    }
};
