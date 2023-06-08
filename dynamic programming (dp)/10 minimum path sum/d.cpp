// TC: O(m*n)
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols,0));
    dp[0][0]=grid[0][0];
    for(int i=1;i<rows;i++) dp[i][0]=dp[i-1][0]+grid[i][0];
    for(int j=1;j<cols;j++) dp[0][j]=dp[0][j-1]+grid[0][j];
    
    for(int i=1;i<rows;i++)
        for(int j=1;j<cols;j++)
            dp[i][j]=grid[i][j]+min(dp[i-1][j], dp[i][j-1]);
    return dp[rows-1][cols-1];
}

int main(){
    /*
    19 18 20 13 20 18 
    16 3 16 5 10 9 
    3 2 6 18 8 16 
    */
    vector<vector<int>> grid={
        {19,18,20,13,20,18},
        {16,3,16,5,10,9},
        {3,2,6,18,8,16}
    };
    cout<<minSumPath(grid)<<endl;
    return 0;
}