// TC: O(n*target)
// SC: O(n*target)
#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    for (int i=0; i<n; i++) dp[i][0] = 1;
    for (int j=denominations[0]; j<=value; j+=denominations[0]) dp[0][j] = 1;
    for (int i=1; i<n; i++){
        for (int j=1; j<=value; j++){
            dp[i][j] = dp[i-1][j] + (j>=denominations[i]?dp[i][j-denominations[i]]:0);
        }
    }
    return dp[n-1][value];
}

int main() {
/*
1 2 3
4
*/
    int n=3, value=4;
    int denominations[n] = {1, 2, 3};
    cout << countWaysToMakeChange(denominations, n, value) << endl;
    return 0;
}