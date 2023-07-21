// TC: O(n)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), mn=prices[0], mx=prices[0], profit=0;
        for(int i=1;i<n;i++){
            if (prices[i]<mn){
                mn=prices[i];
                mx=prices[i];
            }
            else if (prices[i]>mx){
                mx=prices[i];
                profit=max(profit, mx-mn);
            }   
        }
        return profit;
    }
};

int main(){
    
    return 0;
}