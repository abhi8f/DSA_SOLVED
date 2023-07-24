// TC: O(n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    int r(int i, int pre, vector<int>& nums, vector<vector<int>> &mv) {
        if (i<0) return 0;
        if (mv[i][pre]!=-1) return mv[i][pre];
        return mv[i][pre] = max(r(i-1,pre,nums, mv), nums[i]<nums[pre]?1+r(i-1,i,nums, mv):0);
    }

   public:
    int lengthOfLIS(vector<int>& nums) {
        nums.push_back(INT_MAX);
        int n=nums.size();
        vector<vector<int>> mv(n,vector<int>(n,-1));
        return r(n-2,n-1,nums.mv);
    }
};

int main() {
    return 0;
}