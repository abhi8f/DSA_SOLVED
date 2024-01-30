class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int l = 0;
        int r = 0;

        while (r < n) {
            if (prices[r] > prices[l]) {
                ans = max(ans, prices[r] - prices[l]);
                r++;
            } else {
                l = r;
                r++;
            }
        }
        return ans;
    }
};
