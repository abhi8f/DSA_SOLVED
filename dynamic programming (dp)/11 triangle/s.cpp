// TC: O(h*(h+1))/2) = O(h^2)
// SC: O(2h) = O(h)
#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<int> pre(n), cur(n);
    for(int j = 0; j < n; j++)
        pre[j] = triangle[n-1][j];
    for(int i = n-2; i >= 0; i--){
        for(int j=0;j<=i;j++)
            cur[j] = triangle[i][j] + min(pre[j], pre[j+1]);
        pre=cur;
        }
    return pre[0];
}

int main(){
    
    return 0;
}