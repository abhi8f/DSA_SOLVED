// TC: O(2n)
// SC: O(4)
#include <bits/stdc++.h>
using namespace std;


int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<int> next(2,0), cur(2,0);
    for (int i = n - 1; i >= 0; i--) {
        cur[0] = max(next[0], next[1] - prices[i] - fee);
        cur[1] = max(next[1], next[0] + prices[i]);
        swap(cur,next);
    }
    return next[0];
}

int main() {
    return 0;
}