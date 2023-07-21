// TC: O(2n)
// SC: O(n) + O(2n) = O(2n)
#include <bits/stdc++.h>
using namespace std;

long m(long* values, int n, int i, bool canBuy, vector<vector<long>> &mv) {
    if (i == n) return 0;
    
    if (mv[i][canBuy]!=-1) return mv[i][canBuy];
    if (canBuy)
        return mv[i][canBuy] = max(m(values, n, i + 1, true,mv), -values[i] + m(values, n, i + 1, false,mv));

    else
        return mv[i][canBuy] = max(m(values, n, i + 1, false,mv), values[i+1] + m(values, n, i+1, true,mv));
}

long getMaximumProfit(long* values, int n) {
    vector<vector<long>> mv(n, vector<long>(2,-1));
    return m(values,n,0,true,mv);
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