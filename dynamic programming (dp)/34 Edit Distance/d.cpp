// TC: O(m*n)
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) dp[i][0] = i;
    for (int j = 1; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) 
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
    return dp[m][n];
}

int main() {
/*
whgtdwhgtdg
aswcfg
*/
    string str1="whgtdwhgtdg", str2="aswcfg";
    cout<<"hello"<<endl;
    cout << editDistance(str1, str2) << endl;
    cout<<"world"<<endl;
    return 0;
}