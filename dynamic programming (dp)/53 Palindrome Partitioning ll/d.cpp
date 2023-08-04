// TC: O(n*n*n)
// SC: O(n*n*n)
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int l, int r, string &s){
    while(l<r)
        if (s[l++]!=s[r--]) return false;
    return true;
}

class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        for(int l=n-2;l>=0;l--){
            if (checkPalindrome(l,n-1,s)) continue;
            int ans=INT_MAX;
            for(int p=l;p<n-1;p++)
                if (checkPalindrome(l,p,s))
                    ans=min(ans, 1+dp[p+1]);
            dp[l]=ans;
        }
        return dp[0];
    }
};

int main(){
    
    return 0;
}