// TC: O(n*n*n)
// SC: O(n*n)
#include <bits/stdc++.h>
using namespace std;


int matrixChainMultiplication(int* arr, int n) {
    if (n==1) return 0;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    // return r(0,n,arr,mv);

    for(int i=n;i>=0;i--){
        for(int j=i+2;j<=n;j++){
            if (i+2==j) {
                dp[i][j]=arr[i]*arr[i+1]*arr[i+2];
                continue;
            }
            int ans=INT_MAX;
            for(int k=i+1;k<j;k++)
                ans=min(
                    ans,
                    arr[i]*arr[k]*arr[j]+dp[i][k]+dp[k][j]
                );
            dp[i][j]=ans;
        }
    }
    return dp[0][n];
}

int main(){
    int arr[]={10,15,20,25};
    cout<<matrixChainMultiplication(arr,3);
    return 0;
}