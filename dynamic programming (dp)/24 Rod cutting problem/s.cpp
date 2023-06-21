// TC: O(n*n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

// using 1 index
int cutRod(vector<int> &price, int n) {
    vector<int> cur(n+1, 0);
    for(int j=1; j<=n; j++) cur[j]=j*price[0];

    for(int i=2;i<=n;i++)
        for(int j=1;j<=n;j++)
            cur[j]=max(cur[j], j>=i?price[i-1]+cur[j-i]:0);
        
    return cur[n];
}

int main() {
    int n=2;
    vector<int> price = {15, 20};
    cout << cutRod(price, n) << endl;
    return 0;
}