class Solution {
private: 
    void getAll(int i, int target, vector<int> &candidates, vector<int> &cur, vector<vector<int>> &ans){
        if (i==candidates.size()) {
            if (target==0) ans.push_back(cur);
            return;
        }
        if (candidates[i]<=target) {
            cur.push_back(candidates[i]);
            getAll(i, target-candidates[i], candidates, cur, ans);
            cur.pop_back();
        }
        getAll(i+1, target, candidates, cur, ans);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        getAll(0, target, candidates, cur, ans);
        return ans;
    }
};
