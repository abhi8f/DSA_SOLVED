// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(vector<int>& prices, int n, int i, int bought) {
    if (i==n) return 0;
    
    if (bought==0 || bought==2)
        return max(r(prices,n,i+1,bought), -prices[i] + r(prices,n,i+1,bought+1));
    else if (bought==1 || bought==3)
        return max(r(prices,n,i+1,bought), +prices[i] + r(prices,n,i+1,bought+1));

    return 0;
}
int maxProfit(vector<int>& prices, int n) {
    if (n<2) return 0;
    return r(prices,n,0,0);
}


int main() {
    vector<int> prices={1,2};
    cout<<maxProfit(prices,2);
}