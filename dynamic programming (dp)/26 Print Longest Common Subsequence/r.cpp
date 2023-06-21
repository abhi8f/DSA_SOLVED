// TC: O(2^(m+n)))
// SC: O(m+n)
#include <bits/stdc++.h>
using namespace std;

vector<int> r(int i, int j, vector<int> &a, vector<int> &b){
    if (i<0 || j<0) return vector<int>();
    if (a[i]==b[j]){
        vector<int> ans = r(i-1, j-1, a, b);
        ans.push_back(a[i]);
        return ans;
    }
    vector<int> ans1 = r(i-1, j, a, b);
    vector<int> ans2 = r(i, j-1, a, b);
    return ans1.size()>ans2.size()?ans1:ans2;
}

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    return r(a.size()-1, b.size()-1, a, b);
}

int main(){
    
    return 0;
}