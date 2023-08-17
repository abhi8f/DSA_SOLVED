// TC: O(exp)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;


bool rec(int i, int j, int l, string &s1, string &s2){
    if (l==1) return s1[i]==s2[j];

    for(int nl=1;nl<l;nl++){
        if (rec(i,j,nl,s1,s2) && rec(i+nl,j+nl,l-nl,s1,s2)) return true;
        if (rec(i,j+nl,l-nl,s1,s2) && rec(i+l-nl,j,nl,s1,s2)) return true;
    }
    return false;
}

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return rec(0,0,s1.length(),s1,s2);
    }
};

int main(){
    
    return 0;
}