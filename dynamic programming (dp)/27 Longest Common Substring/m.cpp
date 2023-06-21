// TC: O(m*n)
// SC: O(m+n) + O(m*n) = O(m*n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, string &s1, string &s2, vector<vector<int>> &mv){
    if (i<0 || j<0) return 0;
    if (mv[i][j]!=-1) return mv[i][j];
    int ans = 0;
    int i2 = i, j2 = j;
    while(i2>=0 && j2>=0 && s1[i2]==s2[j2]) ans++, i2--, j2--;
    return mv[i][j] = max({ans, r(i-1, j, s1, s2, mv), r(i, j-1, s1, s2, mv)});
}

int lcs(string &str1, string &str2){
    int m = str1.size(), n = str2.size();
    vector<vector<int>> mv(m, vector<int>(n, -1));
    return r(m-1, n-1, str1, str2, mv);
}

int main(){
    
    return 0;
}