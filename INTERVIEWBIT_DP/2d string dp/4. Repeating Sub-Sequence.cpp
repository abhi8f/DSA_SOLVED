
int rec(int i, int j, string &A, vector<vector<int>> &dp){
    if (i<0 || j<0) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    if (i==j) return dp[i][j] = max(rec(i-1, j, A, dp), rec(i, j-1, A, dp));
    
    if (A[i]==A[j]) return dp[i][j] = 1 + rec(i-1, j-1, A, dp);
    return dp[i][j] = max(rec(i-1, j, A, dp), rec(i, j-1, A, dp));
}

int Solution::anytwo(string A) {
    int n=A.size();
    vector<vector<int>> dp(n, vector<int>(n,-1));
    int val=rec(n-1, n-1, A, dp);
    return val>1?1:0;
}
