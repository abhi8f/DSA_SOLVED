// TC: O(n*max(A))
// SC: O(n*max(A)) + O(n)
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

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int cost=0;
    int n=B.size();
    int mx=*max_element(A.begin(),A.end());
    vector<vector<int>> dp(n,vector<int>(mx+1,-1));
    
    for(int s: A){
        int cur=rec(n-1,s,B,C,dp);
        cost+=cur;
    }
    return cost;
}

int main(){
    
    return 0;
}