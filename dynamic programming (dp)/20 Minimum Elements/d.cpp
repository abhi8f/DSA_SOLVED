// TC: O(n*x)
// SC: O(n*x)
#include <bits/stdc++.h>
using namespace std;

int minimumElements(vector<int> &num, int x) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 1e8));
    for (int i = 0; i < n; i++) dp[i][0] = 0;
    for (int j = num[0]; j <= x; j += num[0]) dp[0][j] = j / num[0];

    if (num[0] <= x) dp[0][num[0]] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int m = 1; m <= j / num[i]; m++)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - m * num[i]] + m);
        }
    return dp[n - 1][x] == 1e8 ? -1 : dp[n - 1][x];
}

int main() {
    /*
4 10
4 1 2 6

    */
    int n = 2, x = 11;
    vector<int> num = {2, 1};
    cout << minimumElements(num, x);
    return 0;
}