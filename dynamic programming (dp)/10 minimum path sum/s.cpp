// TC: O(m*n)
// SC: O(2n) = O(n)
#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<int> pre(cols,0), cur(cols,0);
    pre[0]=grid[0][0];
    for(int j=1;j<cols;j++) pre[j]=pre[j-1]+grid[0][j];
    
    for(int i=1;i<rows;i++){
        cur[0]=pre[0]+grid[i][0];
        for(int j=1;j<cols;j++)
            cur[j]=grid[i][j]+min(pre[j], cur[j-1]);
        pre=cur;
    }
    return pre[cols-1];
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