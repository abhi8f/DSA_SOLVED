// TC: O(m*n)
// SC: O(m+n) + O(m*n) = O(m*n)
#include <bits/stdc++.h>
using namespace std;

int memoizaion(int n, int m, vector< vector< int> > &mat, vector<vector<int>> &mv) {
    if (n < 0 || m < 0) return 0;
    if (mat[n][m]==-1) return 0;
    if (n == 0 && m == 0) return 1;
    if (mv[n][m] != -1) return mv[n][m];
    return mv[n][m] = memoizaion(n - 1, m, mat, mv) + memoizaion(n, m - 1, mat, mv);
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> mv(n, vector<int>(m, -1));
    return memoizaion(n-1, m-1, mat, mv);
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
