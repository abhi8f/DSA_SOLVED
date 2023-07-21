// TC: O(2n)
// SC: O(2n)
#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long* values, int n) {
    if(n<1) return 0;
    vector<vector<long>> dp(n, vector<long>(2,0));
    dp[n-1][0]=values[n-1];
    for(int i=n-2;i>=0;i--){
        dp[i][1]=max(dp[i+1][1], -values[i]+dp[i+1][0]);
        dp[i][0]=max(dp[i+1][0], +values[i]+dp[i+1][1]);
    }
    return dp[0][1];
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long *arr =new long[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<getMaximumProfit(arr,n)<<endl;
    }
    return 0;
}