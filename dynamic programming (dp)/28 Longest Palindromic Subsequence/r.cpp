// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(string s, int i, int j) {
    if(i == j) return 1;
    if(i > j) return 0;
    if(s[i] == s[j]) return 2 + r(s, i+1, j-1);
    return max(r(s, i+1, j), r(s, i, j-1));
}

int longestPalindromeSubsequence(string s) {
    return r(s, 0, s.size()-1);
}

int main() {
    return 0;
}