// TC: O(m*n)
// SC: O(2m) = O(m)
#include <bits/stdc++.h>
using namespace std;

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    if (mat[0][0]==-1) return 0;
    vector<int> pre(m,0), cur(m,0);
    pre[0]=1;
    if (mat[1][0]!=-1) cur[0]=1;
    for(int j=1;j<m;j++) pre[j]=mat[0][j]==-1?0:pre[j-1];

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            cur[j]=mat[i][j]==-1?0:pre[j]+cur[j-1];
        }
        pre=cur;
    }
    return pre[m-1];
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        if (obstacleGrid[0][0]==1) return 0;
        vector<int> pre(m,0), cur(m,0);
        pre[0]=1;
        if (obstacleGrid[1][0]!=1) cur[0]=1;
        for(int j=1;j<m;j++) pre[j]=obstacleGrid[0][j]==1?0:pre[j-1];

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                cur[j]=obstacleGrid[i][j]==1?0:pre[j]+cur[j-1];
            }
            pre=cur;
        }
        return pre[m-1];
    }
};

int main(){
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<vector<int>> mat(m, vector<int>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        Solution s;
        cout<<s.uniquePathsWithObstacles(mat)<<endl;
    }
    return 0;
}
