class Solution {
  public:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vv, vector<pair<int, int>> &v, int i, int j, int is, int js){
        int row = grid.size(), col = grid[0].size();
        if(i<0 || i>=row || j<0 || j>=col || !grid[i][j] || vv[i][j]) return;
        vv[i][j] = true;
        v.push_back({i-is, j-js});
        dfs(grid, vv, v,i+1, j, is, js);
        dfs(grid, vv, v,i-1, j, is, js);
        dfs(grid, vv, v,i, j+1, is, js);
        dfs(grid, vv, v,i, j-1, is, js);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> vv(row, vector<bool>(col, false));
        set<vector<pair<int, int>>> s;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] && !vv[i][j]){
                    vector<pair<int, int>> v;
                    dfs(grid, vv, v, i, j, i, j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};
