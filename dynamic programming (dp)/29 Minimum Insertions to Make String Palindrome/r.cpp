// TC: O(2^n)
// SC: O(2n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, string &s1, string &s2){
    if (i<0 || j<0) return 0;
    if (s1[i]==s2[j]) return 1+r(i-1, j-1, s1, s2);
    return max(r(i-1, j, s1, s2), r(i, j-1, s1, s2));
}

int minInsertion(string &str) {
    int n = str.size();
    string rev = str;
    reverse(rev.begin(), rev.end());
    return n - r(n-1, n-1, str, rev);
}

int main() {
    return 0;
}