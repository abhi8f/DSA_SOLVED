// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

int r(vector<int> &prices, int n, int k, int i, int s) {
    if (i == n || s == 2 * k) return 0;

    return max(
        r(prices, n, k, i + 1, s),
        s % 2 == 0 ? -prices[i] + r(prices, n, k, i + 1, s + 1)
                   : +prices[i] + r(prices, n, k, i + 1, s + 1));
}

int maximumProfit(vector<int> &prices, int n, int k) {
    return r(prices, n, k, 0, 0);
}

int main(){
    
    return 0;
}