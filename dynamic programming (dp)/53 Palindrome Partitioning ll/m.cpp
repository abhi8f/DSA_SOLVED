// TC: O(n*n*n)
// SC: O(n) + O(n*n*n)
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int l, int r, string &s){
    while(l<r)
        if (s[l++]!=s[r--]) return false;
    return true;
}

int rec(int l, int r, string &s, vector<int> &dp){
    if (l==r) return 0;
    if (dp[l]!=-1) return dp[l];
    if (checkPalindrome(l,r,s)) return dp[l] = 0;
    int ans=INT_MAX;
    for(int p=l;p<r;p++){
        if (checkPalindrome(l,p,s))
            ans=min(ans, 1+rec(p+1,r,s,dp));
    }
    return dp[l] = ans;
}

class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return rec(0,n-1,s,dp);
    }
};

int main(){
    
    return 0;
}