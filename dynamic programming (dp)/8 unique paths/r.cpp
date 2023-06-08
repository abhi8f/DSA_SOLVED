// TC: O(2^(m*n))
// SC: O(m+n)
#include <bits/stdc++.h>
using namespace std;

int r(int m, int n) {
    if (m < 0 || n < 0) return 0;
    if (m == 0 || n == 0) return 1;
    return r(m - 1, n) + r(m, n - 1);
}

int uniquePaths(int m, int n) {
    return r(m-1, n-1);
}

int main() {
    cout<<uniquePaths(2,2)<<endl;
    cout<<uniquePaths(3,2)<<endl;
    cout<<uniquePaths(1,1)<<endl;
    return 0;
}