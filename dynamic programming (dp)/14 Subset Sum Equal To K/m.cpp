// TC: O(n*k)
// SC: O(n) + O(n*k) = O(n*k)
#include <bits/stdc++.h>
using namespace std;

bool r(int i, int k, vector<int> &arr, vector<vector<int>> &mv) {
    if (i<0) return k==0?true:false;
    if (mv[i][k] != -1) return mv[i][k];
    return mv[i][k]=((k - arr[i]) < 0 ? false:r(i-1, k-arr[i], arr, mv)) || r(i-1, k, arr, mv);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> mv(n, vector<int>(k + 1, -1));
    return r(n-1, k, arr, mv);
}

int main() {
    return 0;
}