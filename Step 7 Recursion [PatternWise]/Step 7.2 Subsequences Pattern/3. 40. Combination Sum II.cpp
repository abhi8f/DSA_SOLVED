class Solution {
private: 
    void getAllUnique(int i, int tar, vector<int> &cand, int n, vector<int> &cur, vector<vector<int>> &ans) {
        if (tar==0) {
            ans.push_back(cur);
            return;
        }
        if (i==n) return;
        if (cand[i]>tar) return;
        cur.push_back(cand[i]);
        getAllUnique(i+1, tar-cand[i], cand, n, cur, ans);
        cur.pop_back();
        for(int j = i+1; (j<n && cand[j]<=tar); j++){
            if (cand[j]==cand[j-1]) continue;
            cur.push_back(cand[j]);
            getAllUnique(j+1, tar-cand[j], cand, n, cur, ans);
            cur.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        getAllUnique(0, target, candidates, candidates.size(), cur, ans);
        return ans;
    }
};
