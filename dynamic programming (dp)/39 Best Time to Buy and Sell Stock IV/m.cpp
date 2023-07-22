// TC: O(n*2k)
// SC: O(n*2k) + O(n)
#include <bits/stdc++.h>
using namespace std;

int r(vector<int> &prices, int n, int k, int i, int s, vector<vector<int>> &mv) {
    if (i == n || s == 2 * k) return 0;
    if (mv[i][s] != -1) return mv[i][s];

    return mv[i][s] = max(
               r(prices, n, k, i + 1, s, mv),
               r(prices, n, k, i + 1, s + 1, mv) + (s % 2 == 0 ? -prices[i] : +prices[i]));
}

int maximumProfit(vector<int> &prices, int n, int k) {
    vector<vector<int>> mv(n, vector<int>(2 * k, -1));
    return r(prices, n, k, 0, 0, mv);
}

int main() {
    return 0;
}