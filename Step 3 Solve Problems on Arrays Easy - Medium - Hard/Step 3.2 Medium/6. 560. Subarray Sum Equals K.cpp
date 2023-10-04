class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int preSum=0, ans=0;
        m[0]=1;
        for(int x: nums) {
            preSum+=x;
            ans+=m[preSum-k];
            m[preSum]++;
        }
        return ans;
    }
};