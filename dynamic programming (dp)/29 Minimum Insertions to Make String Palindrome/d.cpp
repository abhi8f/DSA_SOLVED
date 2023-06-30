// TC: O(n*n)
// SC: O(n*n)
#include <bits/stdc++.h>
using namespace std;

int minInsertion(string &str) {
    int n = str.size();
    string rev = str;
    reverse(rev.begin(), rev.end());
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (str[i-1]==rev[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return n-dp[n][n];
}

int main() {
    string s="wxwpncnsmtntswuatzidmhsbtfkspobxdgibvpzsrjcszbpttpmixgw";
    cout<<minInsertion(s)<<"\n";
    return 0;
}