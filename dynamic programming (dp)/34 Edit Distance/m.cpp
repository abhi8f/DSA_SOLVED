// TC: O(m*n)
// SC: O(m+n) + O(m*n) = O(m*n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, string &str1, string &str2, vector<vector<int>> &mv){
    if(i == -1) return j+1;
    if(j == -1) return i+1;
    if(mv[i][j] != -1) return mv[i][j];
    if(str1[i] == str2[j]) return mv[i][j] = r(i-1, j-1, str1, str2, mv);
    return mv[i][j] = 1 + min({r(i-1, j-1, str1, str2, mv), r(i-1, j, str1, str2, mv), r(i, j-1, str1, str2, mv)});
}


int editDistance(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    vector<vector<int>> mv(m, vector<int>(n, -1));
    return r(m-1, n-1, str1, str2, mv);
}

int main(){
    
    return 0;
}