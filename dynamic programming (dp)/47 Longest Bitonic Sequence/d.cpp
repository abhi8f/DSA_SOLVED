// TC: O(n*n*2)
// SC: O(n) + O(n*n*2)
#include <bits/stdc++.h>
using namespace std;


int longestBitonicSubsequence(vector<int>& arr, int n) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(2,0)));
    for(int j=0;j<n;j++) dp[0][j][0]=arr[0]<arr[j], dp[0][j][1]=max(dp[0][j][0], arr[0]>arr[j]?1:0);
    dp[0][n][0]=dp[0][n][1]=1;

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            dp[i][j][0]=max(
                dp[i-1][j][0],
                (j==n || arr[i]<arr[j])?1+dp[i-1][i][0]:0
            );
            dp[i][j][1]=max({
                dp[i-1][j][1],
                dp[i][j][0],
                (j==n || arr[i]>arr[j])?1+dp[i-1][i][1]:0
            });
        }
    }
    return dp[n-1][n][1];
}

int longestBitonicSubsequence(vector<int>& arr, int n){
	vector<int> dp1(n,1), dp2(n,1);
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if (arr[j]<arr[i] && dp1[i]<dp1[j]+1) dp1[i]=dp1[j]+1;
    
    for(int i=n-1;i>=0;i--)
        for(int j=n-1;j>i;j--)
            if (arr[j]<arr[i] && dp2[i]<dp2[j]+1) dp2[i]=dp2[j]+1;

    int maxV=1;
    for(int i=0;i<n;i++)
        maxV=max(maxV, dp1[i]+dp2[i]-1);
    
    return maxV;
}

int main() {
    vector<int> v={1,2,3,4};
    cout<<endl<<endl<<longestBitonicSubsequence(v,4)<<endl;
    return 0;
}