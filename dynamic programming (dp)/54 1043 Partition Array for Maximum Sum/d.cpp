// TC: O(n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;


class Solution {
   public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);

        for(int l=n-1;l>=0;l--){
            int mv = arr[l];
            int ans = mv + dp[l + 1];
            for (int p = l + 1; p < min(n,l+k); p++) {
                mv = max(mv, arr[p]);
                ans = max(ans, mv * (p - l + 1) + dp[p + 1]);
            }
            dp[l] = ans;
        }
        return dp[0];
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2};
    cout << endl
         << s.maxSumAfterPartitioning(arr, 2) << endl;
    return 0;
}