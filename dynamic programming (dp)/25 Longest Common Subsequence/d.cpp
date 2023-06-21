// TC: O(m*n)
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t) {
    int row = s.size(), col = t.size();
    if (row == 0 || col == 0) return 0;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for (int j = 0; j < col; j++) dp[0][j] = s[0] == t[j] ? 1 : 0;
    for (int i = 1; i < row; i++)
        for (int j = 0; j < col; j++)
            dp[i][j] = s[i] == t[j] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
    return dp[row - 1][col - 1];
}

int main() {
    return 0;
}