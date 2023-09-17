class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int a = 0; a < n - 3; a++) {
            if (a!=0 && nums[a]==nums[a-1]) continue;
            for(int b = a + 1; b < n - 2; b++) {
              if (b!=(a+1) && nums[b]==nums[b-1]) continue;
                int l = b + 1, r = n - 1;
                while (l < r) {
                    if (((double)nums[a] + nums[b] + nums[l] + nums[r] - target) == 0){
                        ans.push_back({nums[a], nums[b], nums[l++], nums[r--]});
                        while( l < r && nums[l - 1] == nums[l] ) l++;
                        while( l < r && nums[r + 1] == nums[r] ) r--;
                    }
                    else if (((double)nums[a] + nums[b] + nums[l] + nums[r] - target) < 0) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};