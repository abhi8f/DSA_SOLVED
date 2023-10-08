class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX, l=0, r=nums.size()-1, m;
        while(l<=r){
            m=l+(r-l)/2;
            ans=min(ans, nums[m]);

            if (nums[l]<=nums[m]){
                if (nums[l]<nums[r]) r=m-1;
                else l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};