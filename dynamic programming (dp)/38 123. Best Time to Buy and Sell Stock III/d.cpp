// TC: O(4n)
// SC: O(5n)
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int n) {
    if (n < 2) return 0;
    vector<vector<int>> dp(n + 1, vector<int>(5, 0));

    for (int i = n - 1; i >= 0; i--) 
        for (int j = 0; j < 4; j++) 
            dp[i][j] = max(
                dp[i + 1][j],
                j % 2 == 0 ? -prices[i] + dp[i + 1][j + 1]
                           : +prices[i] + dp[i + 1][j + 1]);
    return dp[0][0];
}

int main() {
    vector<int> prices = {1, 2};
    cout << maxProfit(prices, 2);
}