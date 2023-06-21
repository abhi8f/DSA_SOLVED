// TC: O(n*n)
// SC: O(n) + O(n*n) = O(n*n)
#include <bits/stdc++.h>
using namespace std;

// using 1 index
int r(int i, int l, vector<int> &price, vector<vector<int>> &mv) {
    if (i==0) return 0;
    if (mv[i][l]!=-1) return mv[i][l];
    return mv[i][l] = max(r(i-1, l, price, mv), l>=i?price[i-1]+r(i, l-i, price, mv):0);
}

int cutRod(vector<int> &price, int n) {
    vector<vector<int>> mv(n+1, vector<int>(n+1, -1));
    return r(n, n, price, mv);
}

int main() {
    int n=2;
    vector<int> price = {1, 20};
    cout << cutRod(price, n) << endl;
    return 0;
}