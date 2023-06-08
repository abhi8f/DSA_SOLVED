// TC: O(m*n)
// SC: O(m+n) + O(m*n) = O(m*n)
#include <bits/stdc++.h>
using namespace std;

int m(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &mv){
    if (i==0 && j==0) return grid[i][j];
    if (i<0 || j<0) return INT_MAX;
    if (mv[i][j]!=-1) return mv[i][j];
    return mv[i][j] = grid[i][j]+min(m(i-1,j,grid,mv), m(i,j-1,grid,mv));
}

int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> mv(grid.size(), vector<int>(grid[0].size(),-1));
    return m(grid.size()-1, grid[0].size()-1, grid, mv);
}

int main(){
    
    return 0;
}