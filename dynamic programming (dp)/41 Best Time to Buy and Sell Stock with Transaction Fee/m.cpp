// TC: O(2n)
// SC: O(n) + O(2n)
#include <bits/stdc++.h>
using namespace std;

int r(vector<int> &prices, int fee, int i, bool bought, vector<vector<int>> &mv) {
    if (i == prices.size()) return 0;
    if (mv[i][bought] != -1) return mv[i][bought];
    return mv[i][bought] = max(
               r(prices, fee, i + 1, bought, mv),
               r(prices, fee, i + 1, !bought, mv) + (bought ? +prices[i]
                                                            : -prices[i] - fee));
}

int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> mv(n, vector<int>(2, -1));
    return r(prices, fee, 0, 0, mv);
}

int main() {
    return 0;
}