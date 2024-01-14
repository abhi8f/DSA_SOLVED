class Solution {
private:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first < b.first) return true;
        if (b.first < a.first) return false;
        return a.second >= b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int& x: nums) {
            mp[x]++;
        }
        vector<pair<int, int>> temp;
        for(auto& p: mp) {
            temp.push_back({p.second, p.first});
        }
        sort(temp.begin(), temp.end(), cmp);

        vector<int> ans;
        for(auto& p: temp) {
            for(int i = 0; i<p.first; i++) {
                ans.push_back(p.second);
            }
        }
        return ans;
    }
};
