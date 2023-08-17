// TC: O(n^4)
// SC: O(n) + O(n^3)
#include <bits/stdc++.h>
using namespace std;


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
        vector<vector<vector<short>>> dp(n,vector<vector<short>>(n, vector<short>(n+1,-1)));
        return rec(0,0,s1.length(),s1,s2,dp);
    }
};

int main(){
    
    return 0;
}