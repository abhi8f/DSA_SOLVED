
short rec(int i, int j, const string &A, const string &B, vector<vector<short>> &dp){
    if (i<0 && j<0) return true;
    if (j<0) return false;
    if (i<0){
        while(j>=0 && B[j]=='*') j--;
        if (j<0) return true;
        else return false;
    }
    if (dp[i][j]!=-1) return dp[i][j]; 
    if (B[j]=='*') return dp[i][j] = (rec(i-1, j, A, B, dp) || rec(i, j-1, A, B, dp));
    if (B[j]=='?') return dp[i][j] = rec(i-1, j-1, A, B, dp);
    if (A[i]==B[j]) return dp[i][j] = rec(i-1, j-1, A, B, dp);
    return dp[i][j] = false;
}

int Solution::isMatch(const string A, const string B) {
    string C="";
    C+=B[0];
    for(int i=1; i<B.size(); i++) if (B[i]!='*' || B[i]!=B[i-1]) C+=B[i];
    int m=A.size(), n=C.size();
    vector<vector<short>> dp(m, vector<short>(n, -1));
    return rec(m-1, n-1, A, C, dp);
}
