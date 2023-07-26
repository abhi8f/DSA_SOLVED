// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
   private:
    int r(int i, int pre, vector<int>& nums) {
        if (i==nums.size()) return 0;
        return max(r(i+1,pre,nums), (pre==-1 || nums[i]>nums[pre])?1+r(i+1,i,nums):0);
    }

   public:
    int lengthOfLIS(vector<int>& nums) {
        return r(0,-1,nums);
    }
};

class Solution {
   private:
    int r(int i, int pre, vector<int>& nums) {
        if (i<0) return 0;
        return max(r(i-1,pre,nums), (pre==nums.size() || nums[i]<nums[pre])?1+r(i-1,i,nums):0);
    }

   public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return r(n-1,n,nums);
    }
};

int main() {
    return 0;
}