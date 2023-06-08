// TC: O(2^(m*n))
// SC: O(m+n)
#include <bits/stdc++.h>
using namespace std;

int r(int n, int m, vector< vector< int> > &mat) {
    if (n < 0 || m < 0) return 0;
    if (mat[n][m]==-1) return 0;
    if (n == 0 && m == 0) return 1;
    return r(n - 1, m, mat) + r(n, m - 1, mat);
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return r(n-1, m-1, mat);
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
