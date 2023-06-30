// TC: O(m*n)
// SC: O(2n)
#include <bits/stdc++.h>
using namespace std;

int canYouMake(string &str, string &ptr) {
    int m = str.size(), n = ptr.size();
    vector<int> cur(n+1, 0), prev(n+1, 0);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (str[i-1] == ptr[j-1]) cur[j] = 1 + prev[j-1];
            else cur[j] = max(cur[j-1], prev[j]);
        }
        prev = cur;
    }
    return m-prev[n]+n-prev[n];
}

int main() {
    // abcd anc
    string str="abcd", ptr="anc";
    cout << canYouMake(str, ptr) << endl;
    return 0;
}