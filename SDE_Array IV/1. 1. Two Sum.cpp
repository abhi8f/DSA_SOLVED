class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            if (auto s = m.find(target-nums[i]); s!=m.end())
                return {s->second, i};
            
            m[nums[i]]=i;
        }
        return {};
    }
};


#include <bits/stdc++.h>
string read(int n, vector<int> book, int target) {
    unordered_set<int> s;
    for (int x : book) {
        if (s.find(target - x) != s.end()) return "YES";
        s.insert(x);
    }
    return "NO";
}