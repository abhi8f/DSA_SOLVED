// TC: O(m*n)
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m,0));
    if (mat[0][0]==-1) return 0;
    dp[0][0]=1;
    for(int i=1;i<n;i++) dp[i][0]=mat[i][0]==-1?0:dp[i-1][0];
    for(int j=1;j<m;j++) dp[0][j]=mat[0][j]==-1?0:dp[0][j-1];

    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            dp[i][j]=mat[i][j]==-1?0:dp[i-1][j] + dp[i][j-1];
    
    return dp[n-1][m-1];
}


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
        cout<<mazeObstacles(m,n,mat)<<endl;
    }
    return 0;
}
