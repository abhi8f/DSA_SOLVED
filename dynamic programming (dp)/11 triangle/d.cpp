// TC: O(h*(h+1))/2) = O(h^2)
// SC: (h^2)
#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int j = 0; j < n; j++)
        dp[n-1][j] = triangle[n-1][j];
    for(int i = n-2; i >= 0; i--)
        for(int j=0;j<=i;j++)
            dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
    return dp[0][0];
}

int main(){
    
    return 0;
}