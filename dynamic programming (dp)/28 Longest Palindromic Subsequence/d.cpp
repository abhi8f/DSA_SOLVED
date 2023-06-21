// TC: O(n*n)
// SC: O(n*n)
#include <bits/stdc++.h>
using namespace std;

int longestPalindromeSubsequence(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    string rs = s;
    reverse(rs.begin(), rs.end());
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            dp[i][j] = (s[i] == rs[j]) ? ((i == 0 || j == 0) ? 1 : 1 + dp[i-1][j-1]) : max((i == 0 ? 0 : dp[i-1][j]), (j == 0 ? 0 : dp[i][j-1]));
    return dp[n-1][n-1];
}

int main() {
    return 0;
}