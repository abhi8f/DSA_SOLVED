#include<bits/stdc++.h>
#define d(x) cout<<#x<<": "<<x<<endl;
void markParentsAndStart(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parentMap, int start, BinaryTreeNode<int> *&startNode) {
    queue<BinaryTreeNode<int> *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
        BinaryTreeNode<int> *node = nodeQueue.front();
        nodeQueue.pop();
        if (node->data==start) startNode=node;
        if (node->left) {
            parentMap[node->left] = node;
            nodeQueue.push(node->left);
        }
        if (node->right) {
            parentMap[node->right] = node;
            nodeQueue.push(node->right);
        }
    }
    return;
}


int getTimeToBurn(BinaryTreeNode<int> *node, BinaryTreeNode<int> *pre, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parentMap) {
    int leftSide = 0, rightSide = 0, parentSide = 0;
    if (node->left && node->left != pre) {
        leftSide = getTimeToBurn(node->left, node, parentMap);
    }
    if (node->right && node->right != pre) {
        rightSide = getTimeToBurn(node->right, node, parentMap);
    }
    BinaryTreeNode<int> *parent = parentMap[node];
    if (parent != NULL && parent != pre) {
        parentSide = getTimeToBurn(parent, node, parentMap);
    }
    int ans = 1 + max({leftSide, rightSide, parentSide});
    // d(node->data); d(leftSide); d(rightSide); d(parentSide); d(ans); cout<<endl;
    return ans;
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start) {
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parentMap;
    BinaryTreeNode<int> *startNode;
    markParentsAndStart(root, parentMap, start, startNode);
    return -1 + getTimeToBurn(startNode, NULL, parentMap);
}
