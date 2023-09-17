class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int s=nums.size();
        for(int i=0;i<s;i++){
            if (i!=0 && nums[i-1]==nums[i]) continue;
            
            int l=i+1, r=s-1;
            while(l<r){
                if ((nums[i]+nums[l]+nums[r])==0){
                    v.push_back({nums[i],nums[l++],nums[r--]});
                    while(l<r && nums[l-1]==nums[l]) l++;
                    while(l<r && nums[r+1]==nums[r]) r--;
                }
                else if ((nums[i]+nums[l]+nums[r])>0) r--;
                else l++;
            }
        }
        return v;
    }
};


#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int> nums, int n, int K) {
    vector<vector<int>> v;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i != 0 && nums[i - 1] == nums[i]) continue;

        int l = i + 1, r = n - 1;
        while (l < r) {
            if ((nums[i] + nums[l] + nums[r] - K) == 0) {
                v.push_back({nums[i], nums[l++], nums[r--]});
                while (l < r && nums[l - 1] == nums[l]) l++;
                while (l < r && nums[r + 1] == nums[r]) r--;
            } else if ((nums[i] + nums[l] + nums[r] - K) < 0)
                l++;
            else
                r--;
        }
    }
    return v;
}