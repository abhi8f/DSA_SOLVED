class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        queue<pair<TreeNode *, unsigned long long>> nodeQueue;
        nodeQueue.push({root,1});

        int curWidth, levelSize;
        while (!nodeQueue.empty()) {
            levelSize = nodeQueue.size() - 1;

            curWidth = -nodeQueue.front().second;

            while (levelSize--) {
                TreeNode *node = nodeQueue.front().first;
                unsigned long long index = nodeQueue.front().second;
                nodeQueue.pop();

                if (node->left) nodeQueue.push({node->left, index*2});
                if (node->right) nodeQueue.push({node->right, index*2+1});
            }

            TreeNode *last = nodeQueue.front().first;
            unsigned long long index = nodeQueue.front().second;
            nodeQueue.pop();

            if (last->left) nodeQueue.push({last->left, index*2});
            if (last->right) nodeQueue.push({last->right, index*2+1});

            curWidth += index;
            maxWidth = max(maxWidth, curWidth);
        }
        return maxWidth + 1;
    }
};
