void getLeafPaths(BinaryTreeNode<int> *node, string &cur, vector<string> &ans) {
    int l = cur.size();
    cur += to_string(node->data) + " ";
    if (!node->left && !node->right) {
        ans.push_back(cur);
    }
    if (node->left) getLeafPaths(node->left, cur, ans);
    if (node->right) getLeafPaths(node->right, cur, ans);

    int nl = cur.size();
    cur.erase(l, nl - l);
    return;
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector<string> ans;
    if (!root) return ans;
    string cur="";
    getLeafPaths(root, cur, ans);
    return ans;
}
