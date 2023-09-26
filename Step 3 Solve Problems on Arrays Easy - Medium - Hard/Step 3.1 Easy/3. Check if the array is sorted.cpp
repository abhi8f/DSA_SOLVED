int isSorted(int n, vector<int> a) {
    for(int i=1; i<n; i++) if (a[i]<a[i-1]) return 0;
    return 1;
}

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(), cnt=0;
        for(int i=1;i<n;i++) if(nums[i-1]>nums[i]) cnt++;
        
        if(nums[n-1]>nums[0]) cnt++;
        return cnt<=1;
    }
};