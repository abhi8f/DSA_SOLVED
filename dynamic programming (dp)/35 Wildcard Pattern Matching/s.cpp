// TC: O(m*n)
// SC: O(2n)
#include <bits/stdc++.h>
using namespace std;

bool wildcardMatching(string pattern, string text) {
    int m = text.size(), n = pattern.size();
    vector<bool> pre(n+1,false), cur(n+1,false);
    pre[0] = true;
    for(int j=1; j<=n && pattern[j-1]=='*'; j++) pre[j] = true;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (pattern[j-1]=='*') cur[j] = pre[j] || cur[j-1];
            else if (pattern[j-1]=='?' || text[i-1]==pattern[j-1]) cur[j] = pre[j-1];
            else cur[j] = false;
        }
        swap(pre,cur);
        // cur[0] = false;
    }
    return pre[n];
}

int main() {
    /*
*bc*da?*
abccdazzz
    */
    cout << wildcardMatching("*bc*da?*", "abccdazzz");
    return 0;
}