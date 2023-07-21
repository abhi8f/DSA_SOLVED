// TC: O(n)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long* values, int n) {
    long profit =0, min = values[0];
    for(int i=1;i<n;i++) {
        if(values[i] < min)
            min = values[i];
        else if(values[i] > min) {
            profit += values[i] - min;
            min = values[i];
        }
    }
    return profit;
}

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0, min = prices[0];
        for (int i = 0; i < n; i++) {
            if (prices[i] < min)
                min = prices[i];
            else if (prices[i] > min) {
                profit += prices[i] - min;
                min = prices[i];
            }
        }
        return profit;
    }
};

int main() {
    return 0;
}