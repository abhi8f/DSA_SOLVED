// TC: O(m*n)
// SC: O(m) + O(m*n) = O(m*n)
#include <bits/stdc++.h>
using namespace std;

int r(vector<vector<int>> &matrix, int i, int j, int n, int m, vector<vector<int>> &mv) {
    if(i >= n || j<0 || j >= m) return INT_MIN;
    if(i == n-1) return matrix[i][j];
    if(mv[i][j] != INT_MIN) return mv[i][j];
    return mv[i][j] = matrix[i][j] + max(r(matrix, i+1, j-1, n, m, mv),max(r(matrix, i+1, j, n, m, mv), r(matrix, i+1, j+1, n, m, mv)));

}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = INT_MIN;
    vector<vector<int>> mv(m, vector<int>(n, INT_MIN));
    for(int j=0;j<n;j++) {
        ans = max(ans, r(matrix, 0, j, m, n, mv));
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix={
        {-9999,-9888,-9777,-9666,-9555}
    };
    cout<<getMaxPathSum(matrix)<<endl;
    return 0;
}