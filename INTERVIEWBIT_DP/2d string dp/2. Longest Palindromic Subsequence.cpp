int rec(int i, int j, string &A, string &B, vector<vector<int>> &dp){
    if (i<0 || j<0) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    if (A[i]==B[j]) return dp[i][j] = 1 + rec(i-1, j-1, A, B, dp);
    return dp[i][j] = max(rec(i-1, j, A, B, dp), rec(i, j-1, A, B, dp));
}

int Solution::solve(string A) {
    string B=A;
    reverse(B.begin(), B.end());
    int n=A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return rec(n-1, n-1, A, B, dp);
    
}