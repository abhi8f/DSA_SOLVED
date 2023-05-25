// TC: O(n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int d(int n, vector<int> &heights) {
    vector<int> dp(n);
    dp[0]=0; dp[1]=abs(heights[0]-heights[1]);
    for(int i=2;i<n;i++){
        dp[i]=min( abs(heights[i] - heights[i - 1]) + dp[i-1], 
                   abs(heights[i] - heights[i - 2]) + dp[i-2]);
    }
    return dp[n-1];
}

int main() {
    vector<int> heights={10,20,30,10};
    int n=4;
    cout<<d(n,heights)<<endl;
    vector<int> heights2={10, 50, 30};
    int n2=3;
    cout<<d(n2,heights2)<<endl;
    return 0;
}