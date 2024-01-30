class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            auto search = mp.find(nums[i]);
            if (search != mp.end()) {
                if ((i - search->second) <= k) return true;
                search->second = i;
            } else {
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};
