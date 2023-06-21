// TC: O(n*n)
// SC: O(n) + O(n*n) = O(n*n)
#include <bits/stdc++.h>
using namespace std;

int r(string s, int i, int j, vector<vector<int>>& mv) {
    if(i == j) return 1;
    if(i > j) return 0;
    if(mv[i][j] != -1) return mv[i][j];
    if(s[i] == s[j]) return mv[i][j] = 2 + r(s, i+1, j-1, mv);
    return mv[i][j] = max(r(s, i+1, j, mv), r(s, i, j-1, mv));
}

int longestPalindromeSubsequence(string s) {
    int n = s.size();
    vector<vector<int>> mv(n, vector<int>(n, -1));
    return r(s, 0, n-1, mv);
}

int main() {
    return 0;
}