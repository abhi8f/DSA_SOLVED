// TC: O(2^(m*n))
// SC: O(m+n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, vector<vector<int>> &grid){
    if (i==0 && j==0) return grid[i][j];
    if (i<0 || j<0) return INT_MAX;
    return grid[i][j]+min(r(i-1,j,grid), r(i,j-1,grid));
}

int minSumPath(vector<vector<int>> &grid) {
    return r(grid.size()-1, grid[0].size()-1, grid);
}

int main(){
    
    return 0;
}