// TC: O(2^m*2*n) = O(2^(m+n))
// SC: O(n+m)
#include <bits/stdc++.h>
using namespace std;

int r(int i1, int i2, string s, string t) {
    if (i1 < 0 || i2 < 0) return 0;
    if (s[i1] == t[i2])
        return 1 + r(i1 - 1, i2 - 1, s, t);
    else
        return max(r(i1 - 1, i2, s, t), r(i1, i2 - 1, s, t));
}

int lcs(string s, string t) {
    return r(s.size() - 1, t.size() - 1, s, t);
}

int main() {
    return 0;
}