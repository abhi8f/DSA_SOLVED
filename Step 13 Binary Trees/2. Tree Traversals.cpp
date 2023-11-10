class TreeNode {
   public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode *node, vector<int> &inorder) {
    if (node==NULL) return;
    inorderTraversal(node->left, inorder);
    inorder.push_back(node->data);
    inorderTraversal(node->right, inorder);
    return;
}

void preorderTraversal(TreeNode *node, vector<int> &preorder) {
    if (node==NULL) return;
    preorder.push_back(node->data);
    preorderTraversal(node->left, preorder);
    preorderTraversal(node->right, preorder);
    return;
}

void postorderTraversal(TreeNode *node, vector<int> &postorder) {
    if (node==NULL) return;
    postorderTraversal(node->left, postorder);
    postorderTraversal(node->right, postorder);
    postorder.push_back(node->data);
    return;
}
vector<vector<int>> getTreeTraversal(TreeNode *root) {
    vector<vector<int>> ans;
    vector<int> cur;
    inorderTraversal(root, cur);
    ans.push_back(cur);
    cur.clear();
    preorderTraversal(root, cur);
    ans.push_back(cur);
    cur.clear();
    postorderTraversal(root, cur);
    ans.push_back(cur);
    return ans;
}
