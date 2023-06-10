// TC : O(n*m*log(n*m))
// SC : O(n*m) + O(n*m) = O(n*m)
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
  public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vv, int i, int j){
        int row = grid.size(), col = grid[0].size();
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]=='0' || vv[i][j]) return;
        vv[i][j] = true;
        dfs(grid, vv, i+1, j);
        dfs(grid, vv, i-1, j);
        dfs(grid, vv, i, j+1);
        dfs(grid, vv, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> vv(row, vector<bool>(col, false));
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && !vv[i][j]){
                    dfs(grid, vv, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends