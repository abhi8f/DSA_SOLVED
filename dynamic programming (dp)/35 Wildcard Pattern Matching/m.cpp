// TC: O(m*n)
// SC: O(m+n) + O(m*n) = O(m*n)
#include <bits/stdc++.h>
using namespace std;

bool r(int i, int j, string &text, string &pattern, vector<vector<int>> &mv) {
    if (i == -1 && j == -1) return true;
    if (j == -1) return false;
    if (i == -1) {
        while (j > -1 && pattern[j] == '*') j--;
        if (j > -1)
            return false;
        else
            return true;
    }
    if (mv[i][j] != -1) return mv[i][j];
    if (pattern[j] == '*') return mv[i][j] = r(i - 1, j, text, pattern, mv) || r(i, j - 1, text, pattern, mv);
    if (pattern[j] == '?' || text[i] == pattern[j]) return mv[i][j] = r(i - 1, j - 1, text, pattern, mv);
    return false;
}

bool wildcardMatching(string pattern, string text) {
    int m = text.size(), n = pattern.size();
    vector<vector<int>> mv(m,vector<int>(n,-1));
    return r(m - 1, n - 1, text, pattern, mv);
}

int main() {
    /*
    *a*b
    adceb
    */
    cout << wildcardMatching("*a*b", "adceb");
    return 0;
}