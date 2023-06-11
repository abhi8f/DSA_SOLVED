// TC: O(2^(n*sum/2)) = O(2^(n*sum))
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

bool r(int i, int k, vector<int> &arr) {
    if (i<0) return k==0?true:false;
    return r(i-1, k-arr[i], arr) || r(i-1, k, arr);
}

bool canPartition(vector<int> &arr, int n) {
    int sum = 0 ;
    for (int i=0; i<n; i++) sum += arr[i];
    if (sum%2) return false;
    return r(n-1, sum/2, arr);
}

int main() {
    return 0;
}