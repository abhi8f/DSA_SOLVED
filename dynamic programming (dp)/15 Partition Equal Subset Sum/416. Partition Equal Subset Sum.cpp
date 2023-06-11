// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}
class Solution {
   public:
    bool r(int i, int k, vector<int> &nums, vector<vector<int>> &mv) {
        if (i < 0) return k == 0 ? true : false;
        if (mv[i][k] != -1) return mv[i][k];
        return mv[i][k] = ((k - nums[i]) < 0 ? false : r(i - 1, k - nums[i], nums, mv)) || r(i - 1, k, nums, mv);
    }

    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % 2) return false;
        vector<vector<int>> mv(n, vector<int>(sum / 2 + 1, -1));
        return r(n - 1, sum / 2, nums, mv);
    }
};

bool canPartition(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    if (sum % 2) return false;
    sum/=2;
    vector<bool> pre(sum+1, false), cur(sum+1, false);

    pre[0]=true; cur[0]=true;
    if (nums[0]<=sum) pre[nums[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++) 
            cur[j]= pre[j]?true: (j-nums[i]<0?false:pre[j-nums[i]]);
        pre=cur;
    }
    return pre[sum];
}