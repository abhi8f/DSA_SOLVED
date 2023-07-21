// TC: O(n*max(values))
// SC: O(2max(values))
#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long* values, int n) {
    if(n<2) return 0;
    long nextSell=values[n-1], nextBuy=0, curSell, curBuy;
    for(int i=n-2;i>=0;i--){
        curBuy=max(nextBuy, -values[i]+nextSell);
        curSell=max(nextSell, +values[i]+curBuy);
        nextSell=curSell;
        nextBuy=curBuy;
    }
    return curBuy;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(n<2) return 0;
        long nextSell=prices[n-1], nextBuy=0, curSell, curBuy;
        for(int i=n-2;i>=0;i--){
            curBuy=max(nextBuy, -prices[i]+nextSell);
            curSell=max(nextSell, +prices[i]+curBuy);
            nextSell=curSell;
            nextBuy=curBuy;
        }
        return curBuy; 
    }
};

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