class Solution {
private:
    int findMaxPathSum(TreeNode * root, int & maxi) {
    if (root == NULL) return 0;

    int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));
    int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));
    int val = root -> val;
    maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
    return max(leftMaxPath, rightMaxPath) + val;

    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findMaxPathSum(root, ans);
        return ans;
    }
};
