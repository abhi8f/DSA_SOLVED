// TC: O(2^(2n)>>)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;


int r(vector<int> &arr, int i, int pre, bool asc){
    if (i<0) return 0;
    if (asc==true){
        int t1=r(arr,i-1,pre, true), t2=r(arr,i,pre, false), t3=0;
        if (pre==arr.size() || arr[i]>arr[pre]) t3=1+r(arr,i-1,i,true);
        return max(t1,max(t2,t3));
    } else {
        int t1=r(arr,i-1,pre, false), t3=0;
        if (pre==arr.size() || arr[i]<arr[pre]) t3 = 1+r(arr, i-1,i, false);
        return max(t1,t3);
    }
}

int longestBitonicSubsequence(vector<int>& arr, int n) {
    return r(arr, n-1,n, true);
}

int main() {
    return 0;
}