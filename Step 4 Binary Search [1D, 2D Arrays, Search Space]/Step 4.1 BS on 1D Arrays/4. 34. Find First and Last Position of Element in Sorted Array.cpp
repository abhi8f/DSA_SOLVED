class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=-1, e=-1, n=nums.size();
        int l=0, r=n-1, m;
        while(l<=r){
            m=l+(r-l)/2;
            if (nums[m]==target) s=m, r=m-1;
            else if (nums[m]>target) r=m-1;
            else l=m+1;
        }
        l=0, r=n-1;
        while(l<=r){
            m=l+(r-l)/2;
            if (nums[m]==target) e=m, l=m+1;
            else if (nums[m]>target) r=m-1;
            else l=m+1;
        }
        return {s,e};
    }
};