// TC: O(m*n)
// SC: O(2n) = O(n)
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> pre(n,1), cur(n,1);

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++)
            cur[j]=pre[j]+cur[j-1];
        pre=cur;
    }
    return pre[n-1];
}

int main() {
    cout<<uniquePaths(2,2)<<endl;
    cout<<uniquePaths(3,2)<<endl;
    cout<<uniquePaths(1,1)<<endl;
    return 0;
}