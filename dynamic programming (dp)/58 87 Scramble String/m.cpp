// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout<<#x<<": "<<x<<endl;
int h=1;
#define h() cout<<"h "<<h++<<endl;


bool rec(int l, int r, string part, string &s2, vector<vector<unordered_map<string,bool>>> &dp){
    if (l==r) return part[0]==s2[l];
    if (dp[l][r].find(part)!=dp[l][r].end()) return dp[l][r][part];
    string t1,t2, scr;
    for(int p=l+1;p<=r;p++){
        t1=part.substr(0,p-l);
        t2=part.substr(p-l);
        if (rec(l,p-1,t1,s2,dp) && rec(p,r,t2,s2,dp)) return dp[l][r][part] = true;
        if (rec(l,t2.size()-1+l,t2,s2,dp) && rec(t2.size()+l,r,t1,s2,dp)) return dp[l][r][part] = true;
    }
    return dp[l][r][part] = false;
}
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        vector<vector<unordered_map<string,bool>>> dp(n, vector<unordered_map<string,bool>>(n));
        return rec(0, n-1,s1,s2,dp);
    }
};
int main(){
    Solution s;
    cout<<s.isScramble("great", "rgeat");
    // cout<<s.isScramble("ab", "ba");
    return 0;
}