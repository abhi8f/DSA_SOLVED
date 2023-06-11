// TC: O(n*sum/2) = O(n*sum)
// SC: O(n) + O(n*sum/2) = O(n*sum)
#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum % 2) return false;
    sum/=2;
    vector<vector<bool>> dp(n, vector<bool>(sum+1,false));

    for(int i=0;i<n;i++) dp[i][0]=true;
    if (arr[0]<=sum) dp[0][arr[0]] = true;

    for(int i=1; i<n; i++) 
        for(int j=1; j<=sum; j++) 
            dp[i][j]= dp[i-1][j]?true: (j-arr[i]<0?false:dp[i-1][j-arr[i]]);
    return dp[n-1][sum];
}

int main() {
    return 0;
}