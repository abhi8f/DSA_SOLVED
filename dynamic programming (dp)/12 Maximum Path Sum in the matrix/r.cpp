// TC: O(3^(m*n))
// SC: O(m)
#include <bits/stdc++.h>
using namespace std;

int r(vector<vector<int>> &matrix, int i, int j, int n, int m) {
    if(i >= n || j<0 || j >= m) return INT_MIN;
    if(i == n-1) return matrix[i][j];
    return matrix[i][j] + max(r(matrix, i+1, j-1, n, m),max(r(matrix, i+1, j, n, m), r(matrix, i+1, j+1, n, m)));

}

int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = INT_MIN;
    for(int j=0;j<m;j++) {
        ans = max(ans, r(matrix, 0, j, n, m));
    }
    return ans;
}

int main() {
    return 0;
}