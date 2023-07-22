// TC: O(2^(2n))
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(vector<int> &prices, int fee, int i, bool bought){
    if (i==prices.size()) return 0;
    return max(
        r(prices,fee,i+1,bought),
        r(prices,fee,i+1,!bought) + (bought?+prices[i]:-prices[i]-fee)
    );
}

int maximumProfit(int n, int fee, vector<int> &prices) {
    return r(prices,fee,0,0);
}

int main(){
    
    return 0;
}