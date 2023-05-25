// TC: O(3n) = O(n)
// SC: O(3n) = O(n)
#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(3,-1));
    for(int j=0;j<3;j++) dp[0][j]=points[0][j];
    
    for(int i=1;i<n;i++){
        dp[i][0]=points[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=points[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=points[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }
    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}

int main(){
    vector<vector<int>> points={
        {10,20,90},
        {10,30,150},
        {40,180,20},
        {160,20,50}
    };
    cout<<ninjaTraining(4,points)<<endl;
    return 0;
}