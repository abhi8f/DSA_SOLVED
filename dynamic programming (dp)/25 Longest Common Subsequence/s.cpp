// TC: O(m*n)
// SC: O(2n) = O(n)
#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t) {
    int row = s.size(), col = t.size();
    if (row == 0 || col == 0) return 0;
    vector<int> pre(col, 0), cur(col, 0);
    for (int j = 0; j < col && j < row; j++) pre[j] = s[0] == t[j] ? 1 : 0;
    for (int i=1; i<row; i++){
        for (int j=0; j<col; j++)
            cur[j]=s[i]==t[j]?1+pre[j-1]:max(pre[j], cur[j-1]);
        pre = cur;
    }
    return pre[col-1];
}

int main() {
    return 0;
}