// TC: O(m*n)
// SC: O(m*n) + O(m+n) = O(m*n)
#include <bits/stdc++.h>
using namespace std;

long long r(int i, int j, string &t, string &s, vector<vector<long long>> &mv){
    if (j<0) return 1;
    if (i<0) return 0;
    if (mv[i][j]!=-1) return mv[i][j];
    return mv[i][j] = r(i-1, j, t, s, mv) + (t[i]==s[j]?r(i-1, j-1, t, s, mv):0);
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<long long>> mv(lt, vector<long long>(ls, -1));
    return r(lt-1, ls-1, t, s, mv)%(long long)(1e9+7);
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