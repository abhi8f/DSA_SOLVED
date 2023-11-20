/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
pair<int, int> getPreSuc(TreeNode *root, int key) {
    pair<int, int> ans = {-1, -1};
    if (!root) return ans;
    
    if (key == root->data) {
        TreeNode *pre = root->left;
        while (pre && pre->right) {
            pre = pre->right;
        }
        if (pre)
            ans.first = pre->data;
        TreeNode *suc = root->right;
        while (suc && suc->left) {
            suc = suc->left;
        }
        if (suc)
            ans.second = suc->data;
        return ans;
    }
    if (key < root->data) {
        ans = getPreSuc(root->left, key);
        if (ans.second == -1) ans.second = root->data;
        return ans;
    }
    ans = getPreSuc(root->right, key);
    if (ans.first == -1) ans.first = root->data;
    return ans;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    return getPreSuc(root, key);
}
