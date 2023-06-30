// TC: O(n*n)
// SC: O(2n) + O(n*n) = O(n*n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, string &s1, string &s2, vector<vector<int>> &mv){
    if (i<0 || j<0) return 0;
    if (mv[i][j]) return mv[i][j];
    if (s1[i]==s2[j]) return mv[i][j] = 1+r(i-1, j-1, s1, s2, mv);
    return mv[i][j] = max(r(i-1, j, s1, s2, mv), r(i, j-1, s1, s2, mv));
}

int minInsertion(string &str) {
    int n = str.size();
    string rev = str;
    reverse(rev.begin(), rev.end());
    vector<vector<int>> mv(n, vector<int>(n, 0));
    return n - r(n-1, n-1, str, rev, mv);
}

int main() {
    return 0;
}