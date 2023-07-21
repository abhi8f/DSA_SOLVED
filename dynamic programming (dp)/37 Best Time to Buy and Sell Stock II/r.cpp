// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

long r(long* values, int n, int i, bool canBuy) {
    if (i >= n) return 0;
    if (canBuy)
        return max(r(values, n, i + 1, true), -values[i] + r(values, n, i + 1, false));

    else
        return max(r(values, n, i + 1, false), values[i] + r(values, n, i+1, true));
}

long getMaximumProfit(long* values, int n) {
    if(n<1) return 0;
    return r(values,n,0,true);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long *arr =new long[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<getMaximumProfit(arr,n)<<endl;
    }
    return 0;
}