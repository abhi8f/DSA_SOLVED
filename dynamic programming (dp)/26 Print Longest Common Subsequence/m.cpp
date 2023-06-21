// TC: O(m*n)
// SC: O(m+n) + O(m*n*(max(m,n)))) = O(m*n*(max(m,n))))
#include <bits/stdc++.h>
using namespace std;

vector<int> r(int i, int j, vector<int> &a, vector<int> &b, vector<vector<vector<int>>> &mv){
    if (i<0 || j<0) return vector<int>();
    if (mv[i][j].size()) return mv[i][j];
    if (a[i]==b[j]){
        vector<int> ans = r(i-1, j-1, a, b, mv);
        ans.push_back(a[i]);
        return mv[i][j] = ans;
    }
    vector<int> ans1 = r(i-1, j, a, b, mv);
    vector<int> ans2 = r(i, j-1, a, b, mv);
    return mv[i][j] = ans1.size()>ans2.size()?ans1:ans2;
}

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    vector<vector<vector<int>>> mv(a.size(), vector<vector<int>>(b.size(), vector<int>()));
    return r(a.size()-1, b.size()-1, a, b, mv);
}

int main(){
    
    return 0;
}