void getLeft(TreeNode<int> *node, vector<int> &ans) {
    if (!node->left && !node->right) return;
    ans.push_back(node->data);
    if (node->left) return getLeft(node->left, ans);
    return getLeft(node->right, ans); 
}

void getLeaf(TreeNode<int> *node, vector<int> &ans) {
    if (!node->left && !node->right) {
        ans.push_back(node->data);
        return;
    }
    if (node->left) getLeaf(node->left, ans);
    if (node->right) getLeaf(node->right, ans);
    return;
}

void getRight(TreeNode<int> *node, vector<int> &ans) {
    if (!node->left && !node->right) return;
    if (node->right) getRight(node->right, ans);
    else getRight(node->left, ans);
    ans.push_back(node->data);
    return;
}


vector<int> traverseBoundary(TreeNode<int> *root) {
    vector<int> ans;
    if (!root) return ans;
    ans.push_back(root->data);
    if (root->left) getLeft(root->left, ans);
    getLeaf(root, ans);
    if (root->right) getRight(root->right, ans);
    return ans;
}
