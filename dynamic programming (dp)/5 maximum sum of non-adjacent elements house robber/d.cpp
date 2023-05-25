// TC: O(n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum1(vector<int> &nums) {
    int n=nums.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    dp[0][0] = 0; dp[0][1] = nums[0];
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][1];
        dp[i][1]=max(dp[i-1][0]+nums[i], dp[i-1][1]);
    }
    return max(dp[n-1][0],dp[n-1][1]);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n=nums.size();
    if (n==1) return nums[0];
    vector<int> dp(n, -1);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++)
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
    
    return dp[n-1];
}


int main() {
    // 1 2 3 1 3 5 8 1 9
    vector<int> v = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    cout << maximumNonAdjacentSum(v) << endl;
    return 0;
}