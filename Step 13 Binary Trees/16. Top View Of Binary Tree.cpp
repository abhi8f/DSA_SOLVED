vector<int> getTopView(TreeNode<int> *root)
{
    map<int, int> lineFirstMap;
    vector<int> ans;
    queue<pair<TreeNode<int> *, int>> nodeQueue;
    nodeQueue.push({root, 0});

    while (!nodeQueue.empty()) {
        TreeNode<int> *node = nodeQueue.front().first;
        int line = nodeQueue.front().second;
        nodeQueue.pop();

        if (lineFirstMap.find(line) == lineFirstMap.end()) 
            lineFirstMap[line] = node->data;
        
        if (node->left) nodeQueue.push({node->left, line - 1});
        if (node->right) nodeQueue.push({node->right, line + 1});
    }

    for(auto &linePair: lineFirstMap) ans.push_back(linePair.second);
    return ans;
}
