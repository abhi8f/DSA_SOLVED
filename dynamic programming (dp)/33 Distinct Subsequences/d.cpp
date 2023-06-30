// TC: O(m*n)
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>> dp(lt, vector<int>(ls, 0));
    dp[0][0] = (t[0] == s[0]);
    for (int i = 1; i < lt; i++) dp[i][0] = dp[i - 1][0] + (t[i] == s[0]);
    
    for (int i=1; i<lt; i++)
        for (int j=1; j<ls; j++)
            dp[i][j] = dp[i-1][j] + (t[i]==s[j]?dp[i-1][j-1]:0);

    return dp[lt - 1][ls - 1];
}

int main() {
    /*
    93 8
efifkdkklhjfkiaadedcegflaefdhgidafacalfakgjidkjggeadkfccbafiggdgdebddghfaffdhgcfkgiialdflacjg
eiecgbld
    */
    int lt = 93, ls = 8;
    string t = "efifkdkklhjfkiaadedcegflaefdhgidafacalfakgjidkjggeadkfccbafiggdgdebddghfaffdhgcfkgiialdflacjg", s = "eiecgbld";
    cout << subsequenceCounting(t, s, lt, ls) << endl;
    return 0;
}