// TC: O(m*n)
// SC: O(m+n) + O(m*n) = O(m*n)
#include <bits/stdc++.h>
using namespace std;

int memoization(int m, int n, vector<vector<int>> &mv) {
    if (m < 0 || n < 0) return 0;
    if (m == 0 || n == 0) return 1;
    if (mv[m][n] != -1) return mv[m][n];
    return mv[m][n] = memoization(m - 1, n, mv) + memoization(m, n - 1, mv);
}

int uniquePaths(int m, int n) {
    vector<vector<int>> mv(m, vector<int>(n, -1));
    return memoization(m-1, n-1, mv);
}

int main() {
    cout<<uniquePaths(2,2)<<endl;
    cout<<uniquePaths(3,2)<<endl;
    cout<<uniquePaths(1,1)<<endl;
    return 0;
}