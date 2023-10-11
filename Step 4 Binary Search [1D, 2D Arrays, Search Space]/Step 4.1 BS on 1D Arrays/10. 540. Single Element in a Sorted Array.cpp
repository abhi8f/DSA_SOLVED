class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        int l=0, r=n-1, m;
        while(l<r){
            m=l+(r-l)/2;
            
            if ((m-l-1)%2==1) { // even
                if (nums[m]==nums[m-1]) r=m;
                else if (nums[m]==nums[m+1]) l=m;
                else return nums[m];
            } else {
                if (nums[m]==nums[m-1]) l=m+1;
                else if (nums[m]==nums[m+1]) r=m-1;
                else return nums[m];
            }
        }
        return nums[l];
    }
};