// TC: O(4n)
// SC: O(4n) + O(n)
#include <bits/stdc++.h>
using namespace std;

int r(vector<int>& prices, int n, int i, int bought, vector<vector<int>>& mv) {
    if (i == n || bought == 4) return 0;

    if (mv[i][bought] != -1) return mv[i][bought];

    return mv[i][bought] = max(
               r(prices, n, i + 1, bought, mv),
               bought % 2 == 0 ? -prices[i] + r(prices, n, i + 1, bought + 1, mv)
                               : +prices[i] + r(prices, n, i + 1, bought + 1, mv));
}
int maxProfit(vector<int>& prices, int n) {
    if (n < 2) return 0;
    vector<vector<int>> mv(n, vector<int>(4, -1));
    return r(prices, n, 0, 0, mv);
}

int main() {
    vector<int> prices = {1, 2};
    cout << maxProfit(prices, 2);
}