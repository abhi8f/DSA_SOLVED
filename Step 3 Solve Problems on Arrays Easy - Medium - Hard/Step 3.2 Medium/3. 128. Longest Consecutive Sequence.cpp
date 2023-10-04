class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(), ans=1, cur=1;
        if (n==0) return 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            if (nums[i]==nums[i-1]) continue;
            if (nums[i]==(nums[i-1] + 1)) cur++;
            else ans=max(ans, cur), cur=1;
        }
        return max(ans, cur);
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0, cur, xx;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int x: nums){
            if (s.find(x-1)!=s.end()) continue;
            cur=1, xx=x;
            while(s.find(xx+1)!=s.end()) cur++, xx++;
            ans=max(ans, cur);
        }
        return max(ans, cur);
    }
};