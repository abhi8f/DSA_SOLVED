// TC: O(m*n)
// SC: O(2n) = O(n) 
#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> pre(n), cur(n);
    for (int j = 0; j < n; j++) pre[j] = matrix[m - 1][j];
    for (int i = m - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++)
            cur[j] = matrix[i][j] + max(pre[max(0,j - 1)], max(pre[j], pre[min(n-1,j + 1)]));
        
        pre = cur;
    }
    int ans = INT_MIN;
    for (int j = 0; j < n; j++) ans = max(ans, pre[j]);
    return ans;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    //  Iterate over matrix
    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            //  Get maximum of all valid path
            matrix[row][col] = matrix[row][col] + max(matrix[row - 1][col], max(matrix[row - 1][max(0, col - 1)], matrix[row - 1][min(m - 1, col + 1)]));
        }
    }

    //  Get the max path sum
    int maxPathSum = INT_MIN;
    for (int col = 0; col < m; col++)
    {
        if (maxPathSum < matrix[n - 1][col])
        {
            maxPathSum = matrix[n - 1][col];
        }
    }
    return maxPathSum;
}

int main() {
    // vector<vector<int>> matrix = {
        // {-9999, -9888, -9777, -9666, -9555}};
    /*
    123
    989
    912
    11
    1
    */
    vector<vector<int>> matrix = {
        {123},
        {989},
        {912},
        {11},
        {1}
    };
    cout << getMaxPathSum(matrix) << endl;
    return 0;
}