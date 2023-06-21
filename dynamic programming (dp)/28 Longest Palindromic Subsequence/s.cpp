// TC: O(n*n)
// SC: O(n*n)
#include <bits/stdc++.h>
using namespace std;


int longestPalindromeSubsequence(string s) {
    int n = s.size();
    vector<int> cur(n, 0), pre(n, 0);
    string rs = s;
    reverse(rs.begin(), rs.end());
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            cur[j] = (s[i] == rs[j]) ? ((i == 0 || j == 0) ? 1 : 1 + pre[j-1]) : max((i == 0 ? 0 : pre[j]), (j == 0 ? 0 : cur[j-1]));
        pre= cur;
    }
    return pre[n-1];
}

int main() {
    return 0;
}