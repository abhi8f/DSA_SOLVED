// TC: O(n*target)
// SC: O(n*target)
#include <bits/stdc++.h>
using namespace std;

int targetSum(int n, int target, vector<int>& arr) {
    int sum=accumulate(arr.begin(), arr.end(), 0);
    if (sum<abs(target) || (sum-target)%2) return 0;
    target = (sum-abs(target))/2;
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    int i=0, zc=0;
    while (i<n && arr[i]==0) zc++, i++;
    dp[i][0] = 1;
    if (arr[i]<=target) dp[i][arr[i]] = 1;
    i++;
    for (; i<n; i++)
        for (int j=0; j<=target; j++)
            dp[i][j] = dp[i-1][j] + (j>=arr[i]?dp[i-1][j-arr[i]]:0);
    
    return dp[n-1][target]*pow(2, zc);
}

int main(){
/*
10 -39
0 13 18 14 15 19 21 2 8 1
*/
    int n=9, target=-39;
    vector<int> arr = {13, 18, 14, 15, 19, 21, 2, 8, 1};
    cout<<targetSum(n, target, arr);
    return 0;
}