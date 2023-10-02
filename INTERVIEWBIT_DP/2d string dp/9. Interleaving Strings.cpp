bool rec(int i, int j, string &s1, string &s2, string &s3, vector<vector<short>> &dp) {
    int m = s1.size(), n = s2.size();
    if (i == m && j == n)
        return true;
    if (dp[i][j]!=-1) return dp[i][j];
    if ((i < m && s1[i] == s3[i + j] && rec(i + 1, j, s1, s2, s3, dp)) ||
        (j < n && s2[j] == s3[i + j] && rec(i, j + 1, s1, s2, s3, dp)))
        return dp[i][j] = true;
    
    return dp[i][j] = false;
}

int Solution::isInterleave(string s1, string s2, string s3) {
    int i = 0, j = 0, m = s1.size(), n = s2.size();
    if ((m + n) != s3.size())
        return false;
    vector<vector<short>> dp(m+1, vector<short>(n+1, -1));
    return rec(0, 0, s1, s2, s3, dp);
}
