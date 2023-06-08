// TC: O(r*c*c*9) = O(r*c*c)
// SC: O(r*c*c)
#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c)));
    for(int j1=0;j1<c;j1++)
        for(int j2=0;j2<c;j2++)
            dp[r-1][j1][j2] = (j1==j2) ? grid[r-1][j1] : grid[r-1][j1] + grid[r-1][j2];
    
    int j1n[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int j2n[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    for(int i=r-2;i>0;i--){
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                int ans = -1e8;
                for(int k=0;k<9;k++){
                    int nj1 = j1 + j1n[k];
                    int nj2 = j2 + j2n[k];
                    if(nj1>=0 && nj1<c && nj2>=0 && nj2<c)
                        ans = max(ans, ((j1==j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]) + dp[i+1][nj1][nj2]);
                }
                dp[i][j1][j2] = ans;
            }
        }
    }
    int ans = -1e8, j1=0, j2=c-1;
    for(int k=0;k<9;k++){
        int nj1 = j1 + j1n[k];
        int nj2 = j2 + j2n[k];
        if(nj1>=0 && nj1<c && nj2>=0 && nj2<c)
            ans = max(ans, ((j1==j2) ? grid[0][j1] : grid[0][j1] + grid[0][j2]) + dp[1][nj1][nj2]);
    }
    return dp[0][j1][j2] = ans;
}

int main() {
    cout << 1e8 << endl;
    return 0;
}
