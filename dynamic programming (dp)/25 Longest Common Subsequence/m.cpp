// TC: O(m*n)
// SC: O(m+n) + O(m*n) = O(m*n)
#include <bits/stdc++.h>
using namespace std;

int r(int i1, int i2, string s, string t, vector<vector<int>>& mv) {
    if (i1 < 0 || i2 < 0) return 0;
    if (mv[i1][i2] != -1) return mv[i1][i2];
    if (s[i1] == t[i2])
        return mv[i1][i2] = 1 + r(i1 - 1, i2 - 1, s, t, mv);
    else
        return mv[i1][i2] = max(r(i1 - 1, i2, s, t, mv), r(i1, i2 - 1, s, t, mv));
}

int lcs(string s, string t) {
    vector<vector<int>> mv(s.size(), vector<int>(t.size(), -1));
    return r(s.size() - 1, t.size() - 1, s, t, mv);
}

int main() {
    return 0;
}