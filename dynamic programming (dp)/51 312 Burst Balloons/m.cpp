// TC: O(n*n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;

int rec(int l, int r, vector<int>& nums, vector<vector<int>> &dp) {
    if (r-l<2) return 0;
    if (dp[l+1][r-1]!=-1) return dp[l+1][r-1];
    int ans = INT_MIN;
    for (int i = l + 1; i < r; i++) {
        ans = max(
            ans,
            nums[i] * (l == -1 ? 1 : nums[l]) * (r == nums.size() ? 1 : nums[r]) +
                rec(l, i, nums,dp) + rec(i, r, nums,dp));
    }
    return dp[l+1][r-1] = ans;
}

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return rec(-1,nums.size(),nums,dp);
    }
};

int main() {
    return 0;
}