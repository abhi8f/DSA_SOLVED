// TC: O(n*n)
// SC: O(2n)
#include <bits/stdc++.h>
using namespace std;

int minInsertion(string &s) {
    int n = str.size();
    string rev = str;
    reverse(rev.begin(), rev.end());
    vector<int> pre(n+1, 0), cur(n+1, 0);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (str[i-1]==rev[j-1]) cur[j] = 1+pre[j-1];
            else cur[j] = max(pre[j], cur[j-1]);
        }
        pre = cur;
    }
    return n-pre[n];
}

int main() {
    string s="wxwpncnsmtntswuatzidmhsbtfkspobxdgibvpzsrjcszbpttpmixgw";
    cout<<minInsertion(s)<<"\n";
    return 0;
}