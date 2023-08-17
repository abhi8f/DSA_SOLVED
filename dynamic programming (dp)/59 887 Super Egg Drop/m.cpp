// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
#include "r.h"
using namespace std;

int rec(int bottom, int top, int k, vector<vector<vector<int>>> &dp){
    if (bottom>top) return 0;
    if (dp[bottom][top][k]!=-1) return dp[bottom][top][k];
    int ans=INT_MAX;
    for(int drop=bottom;drop<=top;drop++){
        int breaks=1+rec(bottom,drop-1,k-1);
        int notBreaks=1+rec(drop+1,top,k-1);
        ans=min(ans,max(breaks,notBreaks));
    }
    return dp[bottom][top][k] = ans;
}

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return rec(0,n-1,k);
    }
};