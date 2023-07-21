// TC: O(2n)
// SC: O(2n)
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout<<#x<<":"<<x<<endl;

int r(vector<int>& prices, int n, int i, int bought) {
    if (i==n) return 0;
    int t1=r(prices,n,i+1,bought),t2=0,t3=0;

    if (bought==0)
        t2=-prices[i]+r(prices,n,i+1,bought+1);
    else if (bought==1)
        t2=-prices[i]+r(prices,n,i+1,bought+1),
        t3= prices[i]+r(prices,n,i+1,bought-1);
    else
        t3= prices[i]+r(prices,n,i+1,bought-1);

    d(i);d(t1);d(t2);d(t3);
    return max({t1,t2,t3});
}
int maxProfit(vector<int>& prices, int n) {
    if (n<2) return 0;
    return r(prices,n,0,0);
}


int main() {
    vector<int> prices={3, 3, 5, 0, 3, 1, 4};
    cout<<maxProfit(prices,7);
}