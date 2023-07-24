// TC: O(n*n)
// SC: O(n*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        nums.push_back(INT_MAX);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=1;j<n;j++) dp[0][j]=nums[0]<nums[j]?1:0;

        for(int i=1; i<n-1;i++)
            for(int j=i+1;j<n;j++)
                dp[i][j]=max(dp[i-1][j],nums[i]<nums[j]?1+dp[i-1][i]:0);
        return dp[n-2][n-1];
    }
};

int main() {
    return 0;
}