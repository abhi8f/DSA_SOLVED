// TC: O(n^3)
// SC: O(n) + O(n^3)
#include <bits/stdc++.h>
using namespace std;

///////////////////////        different compared to recusion  ////////////////////     from leetcode

bool rec(int i, int j, int l, string &s1, string &s2, vector<vector<vector<short>>> &dp){
    if (l==1) return s1[i]==s2[j];
    if (dp[i][j][l]!=-1) return dp[i][j][l];

    for(int nl=1;nl<l;nl++){
        if ((rec(i,j,nl,s1,s2,dp) && rec(i+nl,j+nl,l-nl,s1,s2,dp)) || 
            (rec(i,j+nl,l-nl,s1,s2,dp) && rec(i+l-nl,j,nl,s1,s2,dp))) return dp[i][j][l] = true;
    }
    return dp[i][j][l] = false;
}


class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        vector<vector<vector<short>>> dp(n,vector<vector<short>>(n, vector<short>(n+1,0)));
        for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--){
                dp[i][j][1]=s1[i]==s2[j];
                for(int l=2;(l+i)<=n && (l+j)<=n;l++)
                    for(int nl=1;nl<l;nl++)
                        dp[i][j][l] = (dp[i][j][nl] && dp[i+nl][j+nl][l-nl]) || (dp[i+nl][j][l-nl]&&dp[i][j+l-nl][nl]);
            }
        return dp[0][0][n];
    }
};

class Solution {
   public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector dp(n + 1, vector(n, vector<int>(n)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        for (int length = 2; length <= n; length++)
            for (int i = 0; i < n + 1 - length; i++)
                for (int j = 0; j < n + 1 - length; j++)
                    for (int newLength = 1; newLength < length; newLength++)
                        dp[length][i][j] |= (dp[newLength][i][j] && dp[length - newLength][i + newLength][j + newLength]) ||
                                            (dp[newLength][i][j + length - newLength] && dp[length - newLength][i + newLength][j]);

        return dp[n][0][0];
    }
};

int main() {
    Solution s;
    // cout<<s.isScramble("great", "rgeat");
    cout << s.isScramble("abc", "cba");
    return 0;
}