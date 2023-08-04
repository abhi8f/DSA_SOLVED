// TC: O(n*tar)
// SC: O(n*tar)
#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int>& num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    int i=0, zc=0;
    while(i<n && num[i]==0) zc++, i++;
    if (i<n) dp[i][0] = 1;
    if (i<n && num[i] <= tar) dp[i][num[i]] = 1;
    i++;
    for(; i<n; i++) 
        for(int j=0;j<=tar;j++)
            dp[i][j] = dp[i-1][j] + (j>=num[i] ? dp[i-1][j-num[i]] : 0);
    return dp[n-1][tar]*pow(2, zc);
}

int main() {
/*
3 1
1 0 1
*/
    int tar=31;
    vector<int> num{9,7,0,3,9,8,6,5,7,6};
    cout << findWays(num, tar) << endl;
    return 0;
}