// TC: O(n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;


int r(int l, vector<int>& arr, int k, vector<int> &dp) {
    int n = arr.size();
    if (l == n) return 0;
    if (dp[l]!=-1) return dp[l];
    int mv = arr[l];
    int ans = mv + r(l + 1, arr, k, dp);
    for (int p = l + 1; p < n && (p - l + 1) <= k; p++) {
        mv = max(mv, arr[p]);
        ans = max(ans, mv * (p - l + 1) + r(p + 1, arr, k, dp));
    }
    return dp[l] = ans;
}

class Solution {
   public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return r(0, arr, k, dp);
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2};
    cout << endl
         << s.maxSumAfterPartitioning(arr, 2) << endl;
    return 0;
}