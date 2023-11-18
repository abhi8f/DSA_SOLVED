int minVal(Node* root){
	while (root && root->left) {
		root = root->left;
	}
	if (root) return root->data;
	return -1;
}
