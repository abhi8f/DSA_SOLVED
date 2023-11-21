/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
struct info {
    int count = 0;
    int mn = INT_MAX;
    int mx = INT_MIN;
};

info findLargestBST(TreeNode *root) {
    info cur;
    if (!root) return cur;

    info leftPart = findLargestBST(root->left);
    info rightPart = findLargestBST(root->right);


    if ((leftPart.mx > root->data) ||
        (rightPart.mn < root->data)
        ) {
        cur.mn=INT_MIN;
        cur.mx=INT_MAX;
        cur.count = max(leftPart.count, rightPart.count);
        return cur;
    }

    cur.mn = min(root->data, leftPart.mn);
    cur.mx = max(root->data, rightPart.mx);
    cur.count = 1 + leftPart.count + rightPart.count;
    // cout<<cur.count<<endl;
    return cur;
}

int largestBST(TreeNode * root){
    return findLargestBST(root).count;
}
