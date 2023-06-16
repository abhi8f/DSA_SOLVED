// TC: O(n*(sum-d)/2) = O(n*(sum-d))
// SC: O(n) + O(n*(sum-d)/2) = O(n*(sum-d))
#include <bits/stdc++.h>
using namespace std;

long long r(int i, int k, vector<int> &arr, vector<vector<long long>> &mv) {
    if (i < 0) return k == 0 ? 1 : 0;
    if (mv[i][k] != -1) return mv[i][k];
    return mv[i][k] = ((k >= arr[i] ? r(i - 1, k - arr[i], arr, mv) : 0) + r(i - 1, k, arr, mv));
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum-d)<0 || (sum-d)%2) return 0;
    vector<vector<long long>> mv(n, vector<long long>((sum-d)/2+1, -1));
    return r(n-1, (sum-d)/2, arr, mv)%(1000000007);
}

int main() {
    int n = 4, d = 3;
    vector<int> arr = {5, 2, 5, 1};
    cout << countPartitions(n, d, arr);
    return 0;
}