// TC: O(n*x)
// SC: O(n*x)
#include <bits/stdc++.h>
using namespace std;

int minimumElements(vector<int> &num, int x) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 1e8));
    for (int i = 0; i < n; i++) dp[i][0] = 0;
    for (int j=num[0]; j<=x; j+=num[0]) dp[0][j] = j/num[0];

    for(int i=1;i<n;i++)
        for(int j=1;j<=x;j++)
            dp[i][j] = min(dp[i-1][j], j>=num[i] ? dp[i][j-num[i]]+1 : (int)1e8);
    
    return dp[n-1][x] == 1e8 ? -1 : dp[n-1][x];
}

int main() {
    /*
3 7
1 2 3

    */
    int n = 3, x = 7;
    vector<int> num = {3, 2, 1};
    cout << minimumElements(num, x);
    return 0;
}