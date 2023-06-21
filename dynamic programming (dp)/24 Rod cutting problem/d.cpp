// TC: O(n*n)
// SC: O(n*n)
#include <bits/stdc++.h>
using namespace std;

// using 1 index
int cutRod(vector<int> &price, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int j=1; j<=n; j++) dp[1][j]=j*price[0];

    for(int i=2;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=max(dp[i-1][j], j>=i?price[i-1]+dp[i][j-i]:0);
        
    return dp[n][n];
}

int main() {
    int n=2;
    vector<int> price = {15, 20};
    cout << cutRod(price, n) << endl;
    return 0;
}