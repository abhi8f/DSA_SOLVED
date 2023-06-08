// TC: O(n*k)
// SC: O(n*k)
#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1,false));

    for(int i=0;i<n;i++) dp[i][0]=true;
    if (arr[0]<=k) dp[0][arr[0]] = true;

    for(int i=1; i<n; i++) 
        for(int j=1; j<=k; j++) 
            dp[i][j]= dp[i-1][j]?true: (j-arr[i]<0?false:dp[i-1][j-arr[i]]);
    return dp[n-1][k];
}

int main() {
    /*
    4 5
    4 3 2 1
    */
    int n=4, k=5;
    vector<int> arr{4,3,2,1};
    cout<<subsetSumToK(n, k, arr);
    return 0;
}