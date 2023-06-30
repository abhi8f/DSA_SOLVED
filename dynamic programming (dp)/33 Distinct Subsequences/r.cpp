// TC: O(2^(m+n))
// SC: O(m+n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, string &t, string &s){
    if (j<0) return 1;
    if (i<0) return 0;
    return r(i-1, j, t, s) + (t[i]==s[j]?r(i-1, j-1, t, s):0);
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    return r(lt-1, ls-1, t, s);
} 

int main(){
/*
10 3
brootgroot
brt
*/
    int lt=10, ls=3;
    string t="brootgroot", s="brt";
    cout << subsequenceCounting(t, s, lt, ls) << endl;
    return 0;
}