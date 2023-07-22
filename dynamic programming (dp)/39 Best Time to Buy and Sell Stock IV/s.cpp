// TC: O(n*2k)
// SC: O(4k)
#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices, int n, int k) {
    vector<int> next(2 * k + 1, 0), cur(2 * k + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2 * k; j++) 
            cur[j] = max(
                next[j],
                next[j + 1] + (s % 2 == 0 ? -prices[i] : +prices[i]));
        
        swap(next,cur);
    }
    return next[0];
}

int main() {
    return 0;
}