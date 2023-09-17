class Solution {
public:
    int reversePairsByMergeSort(int l, int r, vector<int>& nums){
        if (l>=r) return 0;
        int m = l + (r - l) / 2;
        int ans=reversePairsByMergeSort(l, m, nums) + reversePairsByMergeSort(m+1,r,nums);
        
        int p=l, q=m+1;
        while(p<=m && q<=r){
            if (nums[p]>(double)2*nums[q]) ans+=(m-p+1), q++;
            else p++;
        }
        
        vector<int> temp(r-l+1);
        p=l, q=m+1;
        int t=0;
        while(p<=m && q<=r)
	        if (nums[p]<nums[q]) temp[t++]=nums[p++];
	        else temp[t++]=nums[q++];
        while(p<=m) temp[t++]=nums[p++]; 
        while(q<=r) temp[t++]=nums[q++];

        for(t=l;t<=r;t++) nums[t]=temp[t-l];
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return reversePairsByMergeSort(0, nums.size()-1, nums);
    }
};