// TC: O(2^(n*(sum/2))) = O(2^(n*sum))
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

double r(int i, double k, vector<int> &arr) {
    if (i<0) return abs(k);
    if (k-arr[i] >= 0) return min(r(i-1, k-arr[i], arr), r(i-1, k, arr));
    else return r(i-1, k, arr);
}

int minSubsetSumDifference(vector<int>& arr, int n) {
    double k = 0;
    for (int i=0; i<n; i++) k += arr[i];
    k /= 2;
    return 2*r(n-1, k, arr);
}

int main() {
    int n=3;
    vector<int> arr={20,6,5};
    cout << minSubsetSumDifference(arr, n);
    return 0;
}