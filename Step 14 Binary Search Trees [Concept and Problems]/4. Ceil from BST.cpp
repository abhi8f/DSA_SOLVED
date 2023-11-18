int findCeil(BinaryTreeNode<int> *node, int x){
    if (!node) return -1;

    int ans = -1;
    while (node) {
        if (x == node->data) return x;
        if (x < node->data) {
            ans = node->data;
            node = node->left;
        }
        else node = node->right;
    }
    return ans;
}
