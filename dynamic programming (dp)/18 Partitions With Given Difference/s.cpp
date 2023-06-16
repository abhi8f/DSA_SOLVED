// TC: O(n*(sum-d)/2) = O(n*(sum-d))
// SC: O(n*(sum-d))
#include <bits/stdc++.h>
using namespace std;

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum-d)<0 || (sum-d)%2) return 0;
    int k = (sum-d)/2;
    vector<long long> pre(k+1, 0), cur(k+1, 0);
    int i=0, zc=0;
    while(i<n && arr[i]==0) zc++, i++;
    pre[0] = 1;
    if (arr[i]<=k) pre[arr[i]] = 1;
    i++;
    for (; i<n; i++){
        for (int j=0; j<=k; j++)
            cur[j] = pre[j] + ((j>=arr[i])? pre[j-arr[i]]:0);
        pre = cur;
    }
    return (long long)(pre[k]*pow(2, zc))%1000000007;
}

int main() {
    /*
    4 3
    5 2 6 4
    */
    int n = 4, d = 3;
    vector<int> arr = {5, 2, 6, 4};
    cout << countPartitions(n, d, arr);
    return 0;
}