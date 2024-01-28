class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, pair<int, int>>> vec;
        for(auto& v: points) {
            vec.push_back({v[0]*v[0] + v[1]*v[1], {v[0], v[1]}});
        }
        sort(vec.begin(), vec.end());
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back({vec[i].second.first, vec[i].second.second});
        }
        return ans;
    }
};
