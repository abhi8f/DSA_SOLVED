// TC: O(n*sum/2) = O(n*sum)
// SC: O(sum)
#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n) {
    double k = 0;
    for (int i = 0; i < n; i++) k += arr[i];
    if (k == 0) return 0;
    k /= 2;
    int floatingCase = (int)k == k ? 0 : 1;
    k = (int)k;
    vector<int> pre(k + 1, 0), cur(k + 1, 0);
    for (int i = 0; i <= k; i++) pre[0] = (i - arr[0]) >= 0 ? (i - arr[0]) : i;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++)
            cur[j] = min(pre[j], (j - arr[i]) >= 0 ? pre[j - arr[i]] : INT_MAX);
        pre = cur;
    }
    return 2 * pre[k] + floatingCase;
}

int main() {
    int n=3;
    vector<int> arr={2,2,2};
    cout << minSubsetSumDifference(arr, n);
    return 0;
}