// TC: O(n*value)
// SC: O(value) + O(n*value) = O(n*value)
#include <bits/stdc++.h>
using namespace std;

long r(int i, int value, int *a, vector<vector<long>> &mv){
    if (i<0) return value==0?1:0;
    if (mv[i][value]!=-1) return mv[i][value];
    return mv[i][value] = r(i-1, value, a, mv) + (value>=a[i]?r(i, value-a[i], a, mv):0);
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long>> mv(n, vector<long>(value+1, -1));
    return r(n-1, value, denominations, mv);
}

int main() {
/*
1 2 3
4
*/
    int n=3, value=4;
    int denominations[n] = {1, 2, 3};
    cout << countWaysToMakeChange(denominations, n, value) << endl;
    return 0;
}