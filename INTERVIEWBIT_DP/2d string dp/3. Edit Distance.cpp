int rec(int i, int j, string &A, string &B, vector<vector<int>> &dp){
    if (i<0) return j+1;
    if (j<0) return i+1;
    
    if (dp[i][j]!=-1) return dp[i][j];
    
    if (A[i]==B[j]) return dp[i][j] = rec(i-1, j-1, A, B, dp);
    
    return dp[i][j] = 1 + min({rec(i-1, j, A, B, dp), rec(i, j-1, A, B, dp), rec(i-1, j-1, A, B, dp)});
}



int Solution::minDistance(string A, string B) {
    int m=A.size(),n=B.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return rec(m-1, n-1, A, B, dp);
}
