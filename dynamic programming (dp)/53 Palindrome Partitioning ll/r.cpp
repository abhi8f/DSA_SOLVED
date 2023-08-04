// TC: O(2^n>>)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(int l, int r, string &s){
    while(l<r)
        if (s[l++]!=s[r--]) return false;
    return true;
}

int rec(int l, int r, string &s){
    if (l==r) return 0;
    if (checkPalindrome(l,r,s)) return  0;
    int ans=INT_MAX;
    for(int p=l;p<r;p++){
        if (!checkPalindrome(l,p,s)) continue;
        ans=min(ans, 1+rec(p+1,r,s));
    }
    return  ans;
}

class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        return rec(0,n-1,s);
    }
};

int main(){
    
    return 0;
}