// TC: O(4n)
// SC: O(10)
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int n) {
    if (n < 2) return 0;

    vector<int> next(5,0),cur(5,0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 4; j++) 
            cur[j] = max(
                next[j],
                j % 2 == 0 ? -prices[i] + next[j + 1]
                           : +prices[i] + next[j + 1]);
        swap(next,cur);
    }
    return next[0];
}

int main() {
    vector<int> prices = {1, 2};
    cout << maxProfit(prices, 2);
}