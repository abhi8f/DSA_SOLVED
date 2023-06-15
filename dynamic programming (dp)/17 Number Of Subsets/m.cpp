// TC: O(n*tar)
// SC: O(n) + O(n*tar) = O(n*tar)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int tar, vector<int>& num, vector<vector<int>> &mv) {
    if (i<0) return tar==0 ? 1 : 0;
    if (mv[i][tar] != -1) return mv[i][tar];
    return mv[i][tar] = ((tar >= num[i] ? r(i - 1, tar - num[i], num, mv) : 0) + r(i - 1, tar, num, mv));
}


int findWays(vector<int>& num, int tar) {
    vector<vector<int>> mv(num.size(), vector<int>(tar+1, -1));
    return r(num.size() - 1, tar, num, mv);
}

int main() {
    /*
    3 1
    1 0 1
    */
    int tar = 1;
    vector<int> num{0, 0 , 0, 1};
    cout << findWays(num, tar) << endl;
    return 0;
}