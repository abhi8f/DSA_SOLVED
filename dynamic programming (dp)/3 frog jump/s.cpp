// TC: O(n)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

int s(int n, vector<int> &heights) {
    vector<int> dp(n);
    int pre2=0, pre=abs(heights[0]-heights[1]);
    for(int i=2;i<n;i++){
        dp[i]=min( abs(heights[i] - heights[i - 1]) + pre, 
                   abs(heights[i] - heights[i - 2]) + pre2);
        pre2=pre;
        pre=dp[i];
    }
    return pre;
}

int main() {
    vector<int> heights={10,20,30,10};
    int n=4;
    cout<<s(n,heights)<<endl;
    vector<int> heights2={10, 50, 30};
    int n2=3;
    cout<<s(n2,heights2)<<endl;
    return 0;
}