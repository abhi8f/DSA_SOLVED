// sorting
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lenMax=1, curLen=1, n=nums.size();
        if (n<2) return n;
        for(int i=1; i<n; i++){
            if (nums[i]==nums[i-1]) continue;
            if (nums[i]==(nums[i-1]+1)) curLen++, lenMax=max(lenMax,curLen);
            else curLen=1;
        }
        return lenMax;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLen=0, curLen, x, n=nums.size();
        for(int cur: s){
            if (s.find(cur-1)!=s.end()) continue;
            curLen=1, cur++;
            while(s.find(cur)!=s.end()) curLen++, cur++;
            maxLen=max(maxLen, curLen);
        }
        return maxLen;
    }
};



