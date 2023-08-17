// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout<<#x<<": "<<x<<endl;
int h=1;
#define h() cout<<"h "<<h++<<endl;


bool rec(int l, int r, string part, string &s2){
    if (l==r) return part[0]==s2[l];
    string t1,t2, scr;
    for(int p=l+1;p<=r;p++){
        t1=part.substr(0,p-l);
        t2=part.substr(p-l);
        if (rec(l,p-1,t1,s2) && rec(p,r,t2,s2)) return true;
        if (rec(l,t2.size()-1+l,t2,s2) && rec(t2.size()+l,r,t1,s2)) return true;
    }
    return false;
}
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return rec(0, s1.size()-1,s1,s2);
    }
};
int main(){
    Solution s;
    cout<<s.isScramble("great", "rgeat");
    // cout<<s.isScramble("ab", "ba");
    return 0;
}