vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int> ans;
    queue<BinaryTreeNode<int> *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
        int s = nodeQueue.size();
        ans.push_back(nodeQueue.front()->data);
        while(s--) {
            BinaryTreeNode<int> *node = nodeQueue.front();
            nodeQueue.pop();
            if (node->left) nodeQueue.push(node->left);
            if (node->right) nodeQueue.push(node->right);
        }
    }
    return ans;
}
