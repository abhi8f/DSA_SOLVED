class Solution {
public:
    void generateAll(int i, vector<int>& nums, vector<int> &cur, vector<vector<int>> &ans) {
        if (i<0) {
            ans.push_back(cur);
            return;
        }
        generateAll(i-1, nums, cur, ans);
        cur.push_back(nums[i]);
        generateAll(i-1, nums, cur, ans);
        cur.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        generateAll(nums.size()-1, nums, cur, ans);
        return ans;
    }
};
