// TC: O(n*x)
// SC: O(target) + O(n*x) = O(n*x)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int x, vector<int> &num, vector<vector<int>> &mv) {
    if (x == 0) return 0;
    if (i < 0) return 1e8;
    if (mv[i][x] != -1) return mv[i][x];
    return mv[i][x] = min(r(i - 1, x, num, mv), x >= num[i] ? r(i, x - num[i], num, mv) + 1 : (int)1e8);
}

int minimumElements(vector<int> &num, int x) {
    vector<vector<int>> mv(num.size(), vector<int>(x + 1, -1));
    int ans = r(num.size() - 1, x, num, mv);
    return ans == 1e8 ? -1 : ans;
}

int main() {
    /*
3 7
1 2 3

    */
    int n = 3, x = 7;
    vector<int> num = {1, 2, 3};
    cout << minimumElements(num, x);
    return 0;
}