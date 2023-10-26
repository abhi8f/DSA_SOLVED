class Solution {
private:
    void getSubsets(int i, int n, vector<int> &nums, vector<int> &cur, vector<vector<int>> &ans) {
        ans.push_back(cur);
        for(int j = i; j < n; j++) {
            if (j!=i && nums[j]==nums[j-1]) continue;
            cur.push_back(nums[j]);
            getSubsets(j+1, n, nums, cur, ans);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        getSubsets(0, nums.size(), nums, cur, ans);
        return ans;
    }
};
