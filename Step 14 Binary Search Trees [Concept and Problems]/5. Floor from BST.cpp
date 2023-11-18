int Floor(BinaryTreeNode<int> *node, int input){
	if (!node) return -1;

	int ans = -1; 

	while(node) {
		if (input == node->data) return input;
		if (input < node->data) node = node->left;
		else {
			ans = node->data;
			node = node->right;
		}
	}
	return ans;
}
