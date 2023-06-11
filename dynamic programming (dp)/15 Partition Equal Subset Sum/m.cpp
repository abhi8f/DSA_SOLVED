// TC: O(n*sum/2) = O(n*sum)
// SC: O(n) + O(n*sum/2) = O(n*sum)
#include <bits/stdc++.h>
using namespace std;

bool r(int i, int k, vector<int> &arr, vector<vector<int>> &mv) {
    if (i<0) return k==0?true:false;
    if (mv[i][k] != -1) return mv[i][k];
    return mv[i][k]=((k - arr[i]) < 0 ? false:r(i-1, k-arr[i], arr, mv)) || r(i-1, k, arr, mv);
}

bool canPartition(vector<int> &arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum % 2) return false;
    vector<vector<int>> mv(n, vector<int>(sum / 2 + 1, -1));
    return r(n-1, sum/2, arr, mv);
}

int main() {
    return 0;
}