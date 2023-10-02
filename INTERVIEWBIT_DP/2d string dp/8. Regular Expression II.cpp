short rec(int i, int j, const string &s, const string &p, vector<vector<int>> &dp){
    if (i<0 && j<0) return 1;
    if (j<0) return 0;
    if (i<0){
        if (p[j]=='*') return rec(i, j-2, s, p, dp);
        return 0;
    } 
    if (dp[i][j]!=-1) return dp[i][j];
    if (p[j]=='.' || s[i]==p[j]) return dp[i][j] = rec(i-1, j-1, s, p, dp);
    if (p[j]=='*'){
        if (p[j-1]=='.' || s[i]==p[j-1]) return dp[i][j] = (rec(i-1, j, s, p, dp) || rec(i, j-2, s, p, dp));
        // if () return dp[i][j] = rec(i-1, j, s, p, dp);
        return dp[i][j] = rec(i, j-2, s, p, dp);
    }
    return dp[i][j] = 0;
}

int Solution::isMatch(const string s, const string p) {
    int m=s.size(), n=p.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return rec(m-1, n-1, s, p, dp);
}