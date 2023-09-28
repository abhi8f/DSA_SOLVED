class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur=0, ans=0;
        for(int x: nums){
            if (x==0) ans=max(ans, cur), cur=0;
            else cur++;
        }
        return max(ans, cur);
    }
};

int traffic(int n, int m, vector<int> vehicle) {
    int ans=INT_MIN, right=0, count=0;
    for(int left=0; left<n; left++){
        while(right<n && count<=m){
            if (vehicle[right]==0) count++;
            if (count>m) {
                count--;
                break;
            }
            right++;
        }
        ans=max(ans, right-left);
        if (vehicle[left]==0) count--;
    }
    return ans;
}
