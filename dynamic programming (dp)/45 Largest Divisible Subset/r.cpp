// TC: O(2^n)
// SC: O(n)
// this return only number of elements in vector
#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    int r(vector<int>& nums, int i, int pre) {
        if (i < 0) return 0;
        int t1=r(nums, i - 1, pre), t2=0;
        if (pre == nums.size()){
            t2=1+r(nums,i-1,i);
        }
        else if (nums[i] % nums[pre] == 0 || nums[pre] % nums[i] == 0){
            if (nums[i] > nums[pre]){
                t2=1+r(nums,i-1,i);
            }
            else {
                t2=1+r(nums,i-1,pre);
            }
        }
        return max(t1,t2);
    }

   public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        cout<<r(nums,n-1,n);
        return vector<int>();
    }
};

int main() {
    vector<int> v={4,8,10,240};
    Solution s;
    s.largestDivisibleSubset(v);
    return 0;
}