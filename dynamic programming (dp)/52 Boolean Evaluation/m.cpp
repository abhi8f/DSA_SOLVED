// TC: O(n*n*n)
// SC: O(n) + O(n*n*2)
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << ": " << x << endl;
int h = 1;
#define h() cout << "h " << h++ << endl;

int rec(int l, int r, bool isTrue, string &exp, vector<vector<vector<int>>> &dp) {
    if (l == r) return isTrue == true ? exp[l] == 'T' : exp[l] == 'F';
    if (dp[l][r][isTrue]!=-1) return dp[l][r][isTrue];
    int ans = 0;
    long long lt,lf,rt,rf,cur;
    for (int p = l + 1; p <= r - 1; p += 2) {
        lt = rec(l, p - 1, true, exp, dp);
        lf = rec(l, p - 1, false, exp, dp);
        rt = rec(p + 1, r, true, exp, dp);
        rf = rec(p + 1, r, false, exp, dp);
        cur = 0;
        if (exp[p] == '&')
            cur = isTrue ? lt * rt
                         : lf * rf + lt * rf + lf * rt;
        else if (exp[p] == '|')
            cur = isTrue ? lt * rt + lt * rf + lf * rt
                         : lf * rf;
        else if (exp[p] == '^')
            cur = isTrue ? lt * rf + lf * rt
                         : lt * rt + lf * rf;
        ans+=(int)(cur%1000000007);
    }
    return dp[l][r][isTrue] = ans;
}
int evaluateExp(string &exp) {
    int n=exp.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return rec(0, exp.size() - 1,true, exp, dp);
}

int main() {
    string s = "T^T|F|T";
    cout << evaluateExp(s) << endl;
    return 0;
}