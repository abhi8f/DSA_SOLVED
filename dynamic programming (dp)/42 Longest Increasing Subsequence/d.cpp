// TC: O(n*n)
// SC: O(n*n)
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--)
            for (int j = i - 1; j >= -1; j--)
                dp[i][j + 1] = max(
                    dp[i + 1][j + 1],
                    (j == -1 || nums[i] > nums[j]) ? 1 + dp[i + 1][i + 1] : 0);

        return dp[0][-1 + 1];
    }
};

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int j = 0; j < n; j++) dp[0][j] = nums[0] < nums[j] ? 1 : 0;
        dp[0][n] = 1;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                dp[i][j] = max(
                    dp[i - 1][j],
                    (j == nums.size() || nums[i] < nums[j]) ? 1 + dp[i - 1][i] : 0);

        return dp[n - 1][n];
    }
};

int main() {
    return 0;
}