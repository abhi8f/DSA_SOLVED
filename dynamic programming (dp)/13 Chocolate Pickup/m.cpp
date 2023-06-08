// TC: O(r*c*c*9) = O(r*c*c)
// SC: O(r) + O(r*c*c) = O(r*c*c)
#include <bits/stdc++.h>
using namespace std;

int j1n[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int j2n[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int rec(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &mv) {
    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
    if (i == r - 1) return (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
    if (mv[i][j1][j2] != -1e8) return mv[i][j1][j2];
    int ans = -1e8;
    for (int k = 0; k < 9; k++)
        ans = max(ans, ((j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]) + rec(i + 1, j1 + j1n[k], j2 + j2n[k], r, c, grid, mv));
    return mv[i][j1][j2] = ans;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> mv(r, vector<vector<int>>(c, vector<int>(c, -1e8)));
    return rec(0, 0, c - 1, r, c, grid, mv);
}

int main() {
    cout << 1e8 << endl;
    return 0;
}
