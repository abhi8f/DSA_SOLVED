class Solution {
public:
    int countParts(vector<int> &nums, int maxSum) {
        int count=1, curSum=maxSum;
        for(int x: nums) {
            if (x<=curSum) curSum -= x;
            else count++, curSum = maxSum - x;
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int mid, count;
        while(low <= high) {
            mid = low + (high - low)/2;

            count = countParts(nums, mid);

            if (count <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};