class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                ans.emplace_back(nums[l] * nums[l]);
                l++;
            } else {
                ans.emplace_back(nums[r] * nums[r]);
                r--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
