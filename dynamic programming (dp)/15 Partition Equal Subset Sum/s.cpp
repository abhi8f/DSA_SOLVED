// TC: O(n*sum/2) = O(n*sum)
// SC: O(sum) 
#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum % 2) return false;
    sum/=2;
    vector<bool> pre(sum+1, false), cur(sum+1, false);

    pre[0]=true; cur[0]=true;
    if (arr[0]<=sum) pre[arr[0]] = true;

    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++) 
            cur[j]= pre[j]?true: (j-arr[i]<0?false:pre[j-arr[i]]);
        pre=cur;
    }
    return pre[sum];
}

int main(){
    
    return 0;
}