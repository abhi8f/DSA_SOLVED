class Solution {
    int helper(int valid, int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (i == days.size()) return 0;
        if (valid >= days[i]) return helper(valid, i + 1, days, costs, dp);

        if (dp[i] != -1) return dp[i];

        int d1 = costs[0] + helper(days[i], i + 1, days, costs, dp);
        int d7 = costs[1] + helper(days[i] + 6, i + 1, days, costs, dp);
        int d30 = costs[2] + helper(days[i] + 29, i + 1, days, costs, dp);

        return dp[i] = min({d1, d7, d30});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return helper(INT_MIN, 0, days, costs, dp);
    }
};
