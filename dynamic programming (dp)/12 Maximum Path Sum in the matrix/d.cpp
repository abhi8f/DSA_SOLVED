// TC: O(m*n)
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
    for (int j = 0; j < n; j++) dp[m - 1][j] = matrix[m - 1][j];
    for (int i = m - 2; i >= 0; i--) {
        if (n==1) {
            dp[i][0] = matrix[i][0] + dp[i + 1][0];
            continue;
        }
        dp[i][0] = matrix[i][0] + max(dp[i + 1][0], dp[i + 1][1]);
        dp[i][n - 1] = matrix[i][n - 1] + max(dp[i + 1][n - 1], dp[i + 1][n - 2]);
        for (int j = 1; j < n-1; j++) {
            dp[i][j] = matrix[i][j] + max(dp[i + 1][j - 1], max(dp[i + 1][j], dp[i + 1][j + 1]));
        }
    }
    int ans = INT_MIN;
    for (int j = 0; j < n; j++) ans = max(ans, dp[0][j]);
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {-9999, -9888, -9777, -9666, -9555}};
    cout << getMaxPathSum(matrix) << endl;
    return 0;
}