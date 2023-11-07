class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        vector<int> ans(n1, -1);
        unordered_map<int,int> mp;
        for(int i=0; i<n1; i++) mp[nums1[i]]=i;
        stack<int> stk;

        int cur;
        for(int i=0; i<n2; i++) {
            cur = nums2[i];
            while(stk.empty()==false && cur>stk.top()){
                ans[mp[stk.top()]]=cur;
                stk.pop();
            }
            if (mp.find(cur)!=mp.end()) stk.push(cur);
        }
        return ans;
    }
};
