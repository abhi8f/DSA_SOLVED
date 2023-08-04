// TC: O(n*sum/2) = O(n*sum)
// SC: O(n) + O(n*sum/2) = O(n*sum)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int k, vector<int> &arr, vector<vector<int>> &mv) {
    if (i<0) return abs(k);
    if (mv[i][k] != -1) return mv[i][k];
    if (k-arr[i] < 0) return mv[i][k] = r(i-1, k, arr, mv);
    return mv[i][k] = min(r(i-1, k-arr[i], arr, mv), r(i-1, k, arr, mv));
}

int minSubsetSumDifference(vector<int>& arr, int n) {
    double k = 0;
    for (int i=0; i<n; i++) k += arr[i];
    k /= 2;
    int floatingCase = (int)k==k?0:1;
    k = (int)k;
    vector<vector<int>> mv(n, vector<int>(k+1, -1));
    return 2*r(n-1, k, arr, mv)+floatingCase;
}

int main() {
    int n=3;
    vector<int> arr={20,6,5};
    cout << minSubsetSumDifference(arr, n);
    return 0;
}