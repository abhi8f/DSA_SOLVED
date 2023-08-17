// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;


int rec(int i, int s, const vector<int> &B, const vector<int> &C, vector<vector<int>> &dp){
    if (s==0) return 0;
    if (i<0) return s==0?0:1e7;
    if (dp[i][s]!=-1) return dp[i][s];
    
    int without=rec(i-1,s,B,C,dp);

    int withCur=1e7;
    if (s>=B[i]) withCur=C[i]+rec(i,s-B[i],B,C,dp);
    return dp[i][s] = min({without,withCur});
}

int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int cost=0;
    int n=B.size();
    int mx=*max_element(A.begin(),A.end());
    vector<vector<int>> dp(n+1,vector<int>(mx+1,1e7));
    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int s: A){
        for(int i=1;i<n+1;i++)
            for(int j=1;j<=s;j++)
                dp[i][j]=min(dp[i-1][j], j>=B[i-1]?C[i-1]+dp[i][j-B[i-1]]:10000000);
        cost+=dp[n][s];
    }
    return cost;
}

int main(){
    
    return 0;
}