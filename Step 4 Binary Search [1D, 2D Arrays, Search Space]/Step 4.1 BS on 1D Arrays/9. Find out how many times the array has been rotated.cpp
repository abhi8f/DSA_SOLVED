int findKRotation(vector<int> &nums){
    int ans=0, l=0, r=nums.size()-1, m;
    while(l<=r){
        m=l+(r-l)/2;
        if (nums[l]<=nums[r]){
            if (nums[l]<nums[ans]) ans=l;
            break;
        }

        if (nums[l]<=nums[m]){
            if (nums[l]<nums[ans]) ans=l;
            l=m+1;
        } else {
            if (nums[m]<nums[ans]) ans=m;
            r=m-1;
        }
    }   
    return ans;
}