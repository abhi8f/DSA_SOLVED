
int teamByMergeSort(int l, int r, vector<int> &skill){
    if (l>=r) return 0;
    int m=l+(r-l)/2;
    int ans=teamByMergeSort(l, m, skill) + teamByMergeSort(m+1, r, skill);

    int p=m, q=r;
    while(p>=l && q>m){
        if (skill[p]>(2*skill[q])) p--, ans+=q-m;
        else q--;
    }
    vector<int> tmp(r-l+1);
    int k=r-l;
    p=m, q=r;
    while(p>=l && q>m){
        if (skill[p]==skill[q]) tmp[k--]=skill[p--], tmp[k--]=skill[q--];
        else if (skill[p]>skill[q]) tmp[k--]=skill[p--];
        else tmp[k--]=skill[q--];
    }
    while(p>=l) tmp[k--]=skill[p--];
    while(q>m) tmp[k--]=skill[q--];
    
    for(int i=l; i<=r; i++) skill[i]=tmp[i-l];
    return ans;
}

int team(vector <int> & skill, int n) {
    return teamByMergeSort(0, n-1, skill);
}






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