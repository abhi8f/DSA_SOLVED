class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int count = 1;
        int len = nums.size();
        for(int i = 1; i < len; i++) {
            if (nums[i] != ele) count--;
            else count++;
            if (count < 0) {
                ele = nums[i];
                count = 1;
            }
        }
        return ele;
    }
};
