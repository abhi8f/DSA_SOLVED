#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    void flood(int i2,int j2,int i,int j,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &floodGrid,queue<pair<int,int>> &q){
        if (i2>=0 && j2>=0 && i2<n && j2<m && grid[i2][j2]==1 && floodGrid[i2][j2]>floodGrid[i][j]){
            q.push({i2,j2});
            floodGrid[i2][j2]=floodGrid[i][j]+1;
        }
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> floodGrid(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if (grid[i][j]==2) {
                    q.push({i,j});
                    floodGrid[i][j]=0;
                }
        while(!q.empty()){
            pair<int,int> p=q.front(); q.pop();
            int i=p.first, j=p.second;
            flood(i-1,j,i,j,n,m,grid,floodGrid,q);
            flood(i+1,j,i,j,n,m,grid,floodGrid,q);
            flood(i,j-1,i,j,n,m,grid,floodGrid,q);
            flood(i,j+1,i,j,n,m,grid,floodGrid,q);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if (grid[i][j]!=0 && floodGrid[i][j]>ans) ans=floodGrid[i][j];
        return ans==INT_MAX?-1:ans;
    }
};
int main(){
/*
give this input
3 3
0 1 2 
0 1 2 
2 1 1
*/
    int n=3,m=3;
    vector<vector<int>> grid={
        {2,1,1}
    };
    Solution s;
    cout<<s.orangesRotting(grid);

    return 0;
}