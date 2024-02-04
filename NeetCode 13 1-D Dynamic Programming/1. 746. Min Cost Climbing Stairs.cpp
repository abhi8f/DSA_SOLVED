class Solution {
public:
    int helper(int i, vector<int>& cost, vector<int>& dp) {
        if (i >= cost.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = cost[i];

        ans += min(helper(i + 1, cost, dp), helper(i+2, cost, dp));

        return dp[i] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(helper(0, cost, dp), helper(1, cost, dp));
    }
};
