// TC: O(n*k)
// SC: O(2k) = O(k)
#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> pre(k+1, false), cur(k+1, false);

    pre[0]=true; cur[0]=true;
    if (arr[0]<=k) pre[arr[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++) 
            cur[j]= pre[j]?true: (j-arr[i]<0?false:pre[j-arr[i]]);
        pre=cur;
    }
    return pre[k];
}

int main() {
    /*
    4 5
    4 3 2 1
    */
    int n=4, k=5;
    vector<int> arr{4,3,2,1};
    cout<<subsetSumToK(n, k, arr);
    return 0;
}