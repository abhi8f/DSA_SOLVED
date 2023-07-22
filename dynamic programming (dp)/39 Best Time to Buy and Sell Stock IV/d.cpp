// TC: O(n*2k)
// SC: O(n*2k)
#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2 * k; j++) {
            dp[i][j] = max(
                dp[i + 1][j],
                dp[i + 1][j + 1] + (s % 2 == 0 ? -prices[i] : +prices[i]));
        }
    }
    return dp[0][0];
}

int main() {
    return 0;
}