class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return 0;
        if (n==2) return (nums[0]>nums[1])?0:1;
        if (nums[0]>nums[1]) return 0;
        if (nums[n-1]>nums[n-2]) return n-1;
        
        int l=1, r=n-2, m;
        while(l<=r){
            m=l+(r-l)/2;

            if (nums[m-1]<nums[m] && nums[m]>nums[m+1]) return m;
            else if (nums[m-1]<nums[m]) l=m+1;
            else r=m-1;
        }
        return -1;
    }
};