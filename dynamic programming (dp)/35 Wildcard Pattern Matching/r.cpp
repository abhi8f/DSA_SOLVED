// TC: O(3^(n))
// SC: O(m+n)
#include <bits/stdc++.h>
using namespace std;

bool r(int i, int j, string &text, string &pattern) {
    if (i == -1 && j == -1) return true;
    if (j == -1) return false;
    if (i == -1) {
        while (j > -1 && pattern[j] == '*') j--;
        if (j > -1)
            return false;
        else
            return true;
    }
    if (pattern[j] == '*') return r(i - 1, j, text, pattern) || r(i - 1, j - 1, text, pattern) || r(i, j - 1, text, pattern);
    if (pattern[j] == '?' || text[i] == pattern[j]) return r(i - 1, j - 1, text, pattern);
    return false;
}

bool wildcardMatching(string pattern, string text) {
    int m = text.size(), n = pattern.size();
    return r(m - 1, n - 1, text, pattern);
}

int main() {
    /*
    *a*b
    adceb
    */
    cout << wildcardMatching("*a*b", "adceb");
    return 0;
}