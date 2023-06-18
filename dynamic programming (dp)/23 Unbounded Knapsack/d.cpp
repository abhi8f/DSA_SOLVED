// TC: O(n*w)
// SC: O(n*w)
#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<vector<int>> dp(n, vector<int>(w+1, 0));
    for (int j=weight[0]; j<=w; j++) dp[0][j] = j/weight[0]*profit[0];
    for (int i=1; i<n; i++) 
        for (int j=1; j<=w; j++) 
            dp[i][j] = max(dp[i-1][j], j>=weight[i]?dp[i][j-weight[i]]+profit[i]:INT_MIN);
        
    return dp[n-1][w];
}

int main() {
    return 0;
}