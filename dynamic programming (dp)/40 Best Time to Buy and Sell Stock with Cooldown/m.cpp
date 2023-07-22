// TC: O(2n)
// SC: O(2n) + O(n)
#include <bits/stdc++.h>
using namespace std;

int r(vector<int> &prices, int i, bool bought, vector<vector<int>> &mv) {
    if (i >= prices.size()) return 0;
    if (mv[i][bought] != -1) return mv[i][bought];
    return mv[i][bought] = max(
               r(prices, i + 1, bought, mv),
               bought ? +prices[i] + r(prices, i + 2, false, mv)
                      : -prices[i] + r(prices, i + 1, true, mv));
}

int stockProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> mv(n, vector<int>(2, -1));
    return r(prices, 0, false,mv);
}

int main() {
    return 0;
}