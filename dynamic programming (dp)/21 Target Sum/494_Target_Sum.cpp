// TC: O(n*target)
// SC: O(target)
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if (sum==0 && target==0) return pow(2,n);
        if (sum<abs(target) || (sum-target)%2) return 0;
        target = (sum-abs(target))/2;
        vector<int> cur(target+1, 0);
        int i=0, zc=0;
        while (i<n && nums[i]==0) zc++, i++;
        cur[0] = 1;
        if (nums[i]<=target) cur[nums[i]] = 1;
        i++;
        for (; i<n; i++)
            for (int j=target; j>=0; j--)
                cur[j] = cur[j] + (j>=nums[i]?cur[j-nums[i]]:0);
        
        return cur[target]*pow(2, zc);
    }
};

int main(){
    int target = 0;
    vector<int> arr = {1, 2 ,1};
    cout<<Solution().findTargetSumWays(arr, target);
    return 0;
}