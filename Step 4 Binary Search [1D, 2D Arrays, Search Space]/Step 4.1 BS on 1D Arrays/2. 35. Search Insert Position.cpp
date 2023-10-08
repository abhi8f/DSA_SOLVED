class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=n, l=0, r=n-1, m;
        while(l<=r) {
            m = l + (r-l)/2;
            if (nums[m]>=target) ans=m, r=m-1;
            else l=m+1;
        }  
        return ans;
    }
};