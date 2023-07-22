// TC: O(2^(2n))
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(vector<int> &prices, int i, bool bought){
    if (i>=prices.size()) return 0;
    return max(
        r(prices,i+1,bought),
        bought? +prices[i] +r(prices,i+2,false):-prices[i]+r(prices,i+1,true)
    );
}

int stockProfit(vector<int> &prices){
    return r(prices,0,false);
}

int main(){
    
    return 0;
}