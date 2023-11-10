class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty()) {
            int s = nodeQueue.size() - 1;
            while (s--) {
                TreeNode *node = nodeQueue.front();
                nodeQueue.pop();
                if (node->left) nodeQueue.push(node->left);
                if (node->right) nodeQueue.push(node->right);
            }
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            ans.push_back(node->val);
            if (node->left) nodeQueue.push(node->left);
            if (node->right) nodeQueue.push(node->right);
        }
        return ans;
    }
};
