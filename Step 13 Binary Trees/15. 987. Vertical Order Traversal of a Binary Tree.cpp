class Solution {
   private:
    struct nodeInfo {
        TreeNode *node;
        int order, level;

        nodeInfo(TreeNode *n, int o, int l) : node(n), order(o), level(l) {}
    };

   public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> ans;
        queue<nodeInfo> nodeQueue;
        map<int, map<int, multiset<int>>> orderLevelMap;
        nodeQueue.push(nodeInfo(root, 0, 0));

        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front().node;
            int order = nodeQueue.front().order;
            int level = nodeQueue.front().level;
            nodeQueue.pop();

            orderLevelMap[order][level].insert(node->val);

            if (node->left) nodeQueue.push(nodeInfo(node->left, order - 1, level + 1));
            if (node->right) nodeQueue.push(nodeInfo(node->right, order + 1, level + 1));
        }
        for (auto &orderPair : orderLevelMap) {
            vector<int> curOrderAns;
            for (auto &levelPair : orderPair.second) {
                curOrderAns.insert(curOrderAns.end(), levelPair.second.begin(), levelPair.second.end());
            }
            ans.push_back(curOrderAns);
        }
        return ans;
    }
};
