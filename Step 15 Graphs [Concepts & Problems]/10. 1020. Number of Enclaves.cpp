class Solution {

private: 
    void markEdgeRegion(int i, int j, vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        if ((i+1) < m && grid[i+1][j]==1) {
            grid[i+1][j] = 0;
            markEdgeRegion(i+1, j, grid);
        }
        if ((i-1)>=0 && grid[i-1][j]==1){
            grid[i-1][j] = 0;
            markEdgeRegion(i-1, j, grid);
        }
        if ((j+1) < n && grid[i][j+1]==1) {
            grid[i][j+1] = 0;
            markEdgeRegion(i, j+1, grid);
        }
        if ((j-1)>=0 && grid[i][j-1]==1){
            grid[i][j-1] = 0;
            markEdgeRegion(i, j-1, grid);
        }
        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            if (grid[i][0]==1){
                grid[i][0] = 0;
                markEdgeRegion(i, 0, grid);
            }
            if (grid[i][n-1]==1){
                grid[i][n-1] = 0;
                markEdgeRegion(i, n-1, grid);
            }
        }
        for(int j=0; j<n; j++) {
            if (grid[0][j]==1){
                grid[0][j] = 0;
                markEdgeRegion(0, j, grid);
            }
            if (grid[m-1][j]==1){
                grid[m-1][j] = 0;
                markEdgeRegion(m-1, j, grid);
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (grid[i][j]==1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
