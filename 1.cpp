// TC: O(n*k)
// SC: O(2k) = O(k)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> pre(k+1, 0), cur(k+1, 0);

    pre[0]=1; cur[0]=1;
    if (nums[0]<=k) pre[nums[0]] = 1;

    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++) 
            cur[j]= pre[j] + ((j-nums[i])<0?0:pre[j-nums[i]]);
        pre=cur;
    }
    return pre[k];   
    }
};

int main() {
    int k=2;
    vector<int> nums{1,1 ,1};
    // int k=3;
    // vector<int> nums{1,2 ,3};
    Solution s;
    cout<<s.subarraySum(nums, k);
    // cout<<subsetSumToK(n, k, nums);
    return 0;
}