// TC: O(m*n)
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2) {
    int row = str1.size(), col = str2.size();
    if (row == 0 || col == 0) return 0;
    vector<vector<int>> dp(row, vector<int>(col, 0));
    int ans = 0;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            if (str1[i]==str2[j])ans = max(ans, dp[i][j]=1+(i>0 && j>0?dp[i-1][j-1]:0));
    
    return ans;
}

int main() {
    return 0;
}