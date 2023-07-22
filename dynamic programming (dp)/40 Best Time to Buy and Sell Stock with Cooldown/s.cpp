// TC: O(2n)
// SC: O(6)
#include <bits/stdc++.h>
using namespace std;


int stockProfit(vector<int> &prices) {
    int n = prices.size();
    vector<int> nextNext(2,0), next(2,0), cur(2,0);

    for(int i=n-1;i>=0;i--){
        cur[0]=max(next[0], -prices[i] + next[1]);
        cur[1]=max(next[1], +prices[i] + nextNext[0]);
        swap(nextNext,next);
        swap(next,cur);
    }
    return next[0];
}

int main() {
    return 0;
}