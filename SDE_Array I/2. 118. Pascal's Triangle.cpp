class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> curAns;
            curAns.push_back(1);
            int preLength=ans[i-1].size();
            for(int j=1;j<preLength;j++){
                curAns.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            curAns.push_back(1);
            ans.push_back(curAns);
        }
        return ans;
    }
};